#include "register_types.h"
#include "sadconsole.h"
#include "core/object/class_db.h"
void initialize_sadconsole_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		GDREGISTER_CLASS(SadFont);
		GDREGISTER_CLASS(SadSurface);
		return;
	}
}
void uninitialize_sadconsole_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
