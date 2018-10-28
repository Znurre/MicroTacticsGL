#ifndef RENDERGROUP_H
#define RENDERGROUP_H

#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "IRenderGroup.h"
#include "IRenderGroupDescriptor.h"
#include "IRenderableInstance.h"

template<class TRenderableInstance>
class RenderGroup : public IRenderGroup
{
	public:
		RenderGroup(IRenderGroupDescriptor<TRenderableInstance> &descriptor)
			: m_descriptor(descriptor)
			, m_mapper(m_shader)
		{
		}

		void create()
		{
			m_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, m_descriptor.vertexShader());
			m_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, m_descriptor.fragmentShader());
			m_shader.link();
			m_shader.bind();

			m_vao.create();
			m_vao.bind();

			m_vbo.create();
			m_vbo.bind();

			const BufferDescriptor &buffer = m_descriptor.buffer();

			m_vbo.allocate(buffer.data(), buffer.size());

			for (const VertexAttributeDescriptor &attribute : buffer.attributes())
			{
				m_shader.setAttributeBuffer(attribute.name(), GL_FLOAT, attribute.offset(), attribute.size(), attribute.stride());
				m_shader.enableAttributeArray(attribute.name());
			}

			m_vbo.release();

			m_vao.release();
			m_shader.release();
		}

		void draw(const QMatrix4x4 &matrix) override
		{
			m_shader.bind();
			m_vao.bind();
			m_vbo.bind();

			m_shader.setUniformValue("VP", matrix);

			const BufferDescriptor &buffer = m_descriptor.buffer();

			for (const IRenderableInstance &instance : m_descriptor.instances())
			{
				instance.apply(m_mapper);

				glDrawArrays(GL_TRIANGLES, 0, buffer.length());
			}

			m_vbo.release();
			m_vao.release();
			m_shader.release();
		}

	private:
		IRenderGroupDescriptor<TRenderableInstance> &m_descriptor;
		PropertyMapper m_mapper;

		QOpenGLShaderProgram m_shader;
		QOpenGLVertexArrayObject m_vao;
		QOpenGLBuffer m_vbo;
};

#endif // RENDERGROUP_H
