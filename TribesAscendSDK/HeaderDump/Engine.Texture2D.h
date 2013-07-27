#pragma once
#include "Engine.Texture.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Texture2D : public Texture
	{
	public:
		class Texture2DMipMap
		{
		public:
			ADD_STRUCT(int, SizeY, 56)
			ADD_STRUCT(int, SizeX, 52)
			ADD_STRUCT(Object::UntypedBulkData_Mirror, Data, 0)
		};
		class TextureLinkedListMirror
		{
		public:
			ADD_STRUCT(Object::Pointer, PrevLink, 8)
			ADD_STRUCT(Object::Pointer, Next, 4)
			ADD_STRUCT(Object::Pointer, Element, 0)
		};
		ADD_STRUCT(ScriptArray<byte>, SystemMemoryData, 324)
		ADD_STRUCT(float, Timer, 364)
		ADD_STRUCT(int, FirstResourceMemMip, 360)
		ADD_STRUCT(Object::Pointer, ResourceMem, 356)
		ADD_STRUCT(int, MipTailBaseIdx, 352)
		ADD_STRUCT(int, StreamingIndex, 348)
		ADD_STRUCT(Texture2D::TextureLinkedListMirror, StreamableTexturesLink, 336)
		ADD_STRUCT(Object::ThreadSafeCounter, PendingMipChangeRequestStatus, 320)
		ADD_STRUCT(int, ResidentMips, 316)
		ADD_STRUCT(int, RequestedMips, 312)
		ADD_STRUCT(Object::Guid, TextureFileCacheGuid, 296)
		ADD_STRUCT(ScriptName, TextureFileCacheName, 288)
		ADD_STRUCT(float, ForceMipLevelsToBeResidentTimestamp, 284)
		ADD_BOOL(bGlobalForceMipLevelsToBeResident, 280, 0x10)
		ADD_BOOL(bForceMiplevelsToBeResident, 280, 0x8)
		ADD_BOOL(bHasBeenLoadedFromPersistentArchive, 280, 0x4)
		ADD_BOOL(bHasCancelationPending, 280, 0x2)
		ADD_BOOL(bIsStreamable, 280, 0x1)
		ADD_STRUCT(Texture::TextureAddress, AddressY, 278)
		ADD_STRUCT(Texture::TextureAddress, AddressX, 277)
		ADD_STRUCT(Texture::EPixelFormat, Format, 276)
		ADD_STRUCT(int, OriginalSizeY, 272)
		ADD_STRUCT(int, OriginalSizeX, 268)
		ADD_STRUCT(int, SizeY, 264)
		ADD_STRUCT(int, SizeX, 260)
		ADD_STRUCT(Object::IndirectArray_Mirror, CachedPVRTCMips, 248)
		ADD_STRUCT(Object::IndirectArray_Mirror, Mips, 236)
		void SetForceMipLevelsToBeResident(float Seconds, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2D.SetForceMipLevelsToBeResident");
			byte params[8] = { NULL };
			*(float*)&params[0] = Seconds;
			*(int*)&params[4] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* Create(int InSizeX, int InSizeY, Texture::EPixelFormat InFormat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2D.Create");
			byte params[13] = { NULL };
			*(int*)&params[0] = InSizeX;
			*(int*)&params[4] = InSizeY;
			*(Texture::EPixelFormat*)&params[8] = InFormat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
