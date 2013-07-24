#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Texture2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Texture2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Texture2D : public Texture
	{
	public:
		ADD_VAR(::FloatProperty, Timer, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FirstResourceMemMip, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ResourceMem'!
		ADD_VAR(::IntProperty, MipTailBaseIdx, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StreamingIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Texture2D.TextureLinkedListMirror' for the property named 'StreamableTexturesLink'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.ThreadSafeCounter' for the property named 'PendingMipChangeRequestStatus'!
		ADD_VAR(::IntProperty, ResidentMips, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RequestedMips, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'TextureFileCacheGuid'!
		ADD_VAR(::NameProperty, TextureFileCacheName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceMipLevelsToBeResidentTimestamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGlobalForceMipLevelsToBeResident, 0x10)
		ADD_VAR(::BoolProperty, bForceMiplevelsToBeResident, 0x8)
		ADD_VAR(::BoolProperty, bHasBeenLoadedFromPersistentArchive, 0x4)
		ADD_VAR(::BoolProperty, bHasCancelationPending, 0x2)
		ADD_VAR(::BoolProperty, bIsStreamable, 0x1)
		ADD_VAR(::ByteProperty, AddressY, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AddressX, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Format, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OriginalSizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OriginalSizeX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.IndirectArray_Mirror' for the property named 'CachedPVRTCMips'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.IndirectArray_Mirror' for the property named 'Mips'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
