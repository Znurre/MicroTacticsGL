CONFIG += c++11

SOURCES += \
    main.cpp \
    VertexAttributeDescriptor.cpp \
    BufferDescriptor.cpp \
    MapTileRenderableInstance.cpp \
    MapTileRenderGroupDescriptor.cpp \
    Window.cpp \
    PropertyMapper.cpp \
    MapLoader.cpp \
    MapSelector.cpp \
    Map.cpp

DISTFILES += \
    resources/shaders/tile.frag \
    resources/shaders/tile.vert

HEADERS += \
    Buffer.h \
    VertexAttributeDescriptor.h \
    VertexAttribute.h \
    BufferDescriptor.h \
    IRenderableInstance.h \
    IRenderGroupDescriptor.h \
    MapTileRenderableInstance.h \
    MapTileRenderGroupDescriptor.h \
    IRenderGroup.h \
    RenderGroup.h \
    Window.h \
    PropertyMapper.h \
    MapLoader.h \
    MapSelector.h \
    Map.h \
    IMapTile.h

LIBS += -ltiled
