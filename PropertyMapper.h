#ifndef PROPERTYMAPPER_H
#define PROPERTYMAPPER_H

#include <QOpenGLShaderProgram>

class PropertyMapper
{
	public:
		PropertyMapper(QOpenGLShaderProgram &shader);

		template<class T>
		void setValue(const char *name, T value)
		{
			m_shader.setUniformValue(name, value);
		}

	private:
		QOpenGLShaderProgram &m_shader;
};

#endif // PROPERTYMAPPER_H
