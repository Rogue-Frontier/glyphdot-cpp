#include "register_types.h"
#include "glyph_surface.h"
#include "core/object/class_db.h"
void initialize_glyphdot_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		GDREGISTER_CLASS(GlyphFont);
		GDREGISTER_CLASS(GlyphSurface);
		return;
	}
}
void uninitialize_glyphdot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
