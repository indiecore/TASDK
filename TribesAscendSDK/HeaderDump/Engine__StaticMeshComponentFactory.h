#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.StaticMeshComponentFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class StaticMeshComponentFactory : public MeshComponentFactory
	{
	public:
		ADD_OBJECT(StaticMesh, StaticMesh)
	};
}
#undef ADD_OBJECT
