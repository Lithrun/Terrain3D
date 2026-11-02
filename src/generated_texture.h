// Copyright © 2023-2026 Cory Petkovsek, Roope Palmroos, and Contributors.

#ifndef GENERATEDTEXTURE_CLASS_H
#define GENERATEDTEXTURE_CLASS_H

#include <godot_cpp/classes/image.hpp>

#include "constants.h"

class GeneratedTexture {
	CLASS_NAME_STATIC("Terrain3DGenTex");

private:
	RID _rid = RID();
	Ref<Image> _image;
	bool _dirty = false;
	int _size = 0;
	// Layer layout of a texture array, which every updated layer must match
	Vector2i _layer_size = V2I_ZERO;
	Image::Format _layer_format = Image::FORMAT_MAX;
	bool _layer_mipmaps = false;

public:
	void clear();
	bool is_dirty() const { return _dirty; }
	RID create(const TypedArray<Image> &p_layers);
	void update(const Ref<Image> &p_image, const int p_layer);
	bool fits_layer(const Ref<Image> &p_image) const;
	bool has_layer_mipmaps() const { return _layer_mipmaps; }
	RID create(const Ref<Image> &p_image);
	Ref<Image> get_image() const { return _image; }
	RID get_rid() const { return _rid; }
	int size() const { return _size; }
};

#endif // GENERATEDTEXTURE_CLASS_H