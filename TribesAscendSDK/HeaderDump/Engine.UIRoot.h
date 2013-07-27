#pragma once
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataStore.h"
#include "Engine.UIInteraction.h"
#include "Engine.GameUISceneClient.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIRoot : public Object
	{
	public:
		static const auto DEFAULT_SIZE_X = 1024;
		static const auto DEFAULT_SIZE_Y = 768;
		static const auto MAX_SUPPORTED_GAMEPADS = 4;
		enum EInputPlatformType : byte
		{
			IPT_PC = 0,
			IPT = 1,
			IPT_PS3 = 2,
			IPT_MAX = 3,
		};
		enum EUIDataProviderFieldType : byte
		{
			DATATYPE_Property = 0,
			DATATYPE_Provider = 1,
			DATATYPE_RangeProperty = 2,
			DATATYPE_NetIdProperty = 3,
			DATATYPE_Collection = 4,
			DATATYPE_ProviderCollection = 5,
			DATATYPE_MAX = 6,
		};
		class UIRangeData
		{
		public:
			ADD_BOOL(bIntRange, 16, 0x1)
			ADD_STRUCT(float, NudgeValue, 12)
			ADD_STRUCT(float, MaxValue, 8)
			ADD_STRUCT(float, MinValue, 4)
			ADD_STRUCT(float, CurrentValue, 0)
		};
		class TextureCoordinates
		{
		public:
			ADD_STRUCT(float, VL, 12)
			ADD_STRUCT(float, UL, 8)
			ADD_STRUCT(float, V, 4)
			ADD_STRUCT(float, U, 0)
		};
		class InputKeyAction
		{
		public:
			ADD_STRUCT(ScriptArray<SequenceOp::SeqOpOutputInputLink>, TriggeredOps, 12)
			ADD_STRUCT(ScriptArray<class SequenceOp*>, ActionsToExecute, 24)
			ADD_STRUCT(Object::EInputEvent, InputKeyState, 8)
			ADD_STRUCT(ScriptName, InputKeyName, 0)
		};
		class InputEventParameters
		{
		public:
			ADD_BOOL(bShiftPressed, 28, 0x4)
			ADD_BOOL(bCtrlPressed, 28, 0x2)
			ADD_BOOL(bAltPressed, 28, 0x1)
			ADD_STRUCT(float, DeltaTime, 24)
			ADD_STRUCT(float, InputDelta, 20)
			ADD_STRUCT(Object::EInputEvent, EventType, 16)
			ADD_STRUCT(ScriptName, InputKeyName, 8)
			ADD_STRUCT(int, ControllerId, 4)
			ADD_STRUCT(int, PlayerIndex, 0)
		};
		class SubscribedInputEventParameters : public InputEventParameters
		{
		public:
			ADD_STRUCT(ScriptName, InputAliasName, 32)
		};
		class UIAxisEmulationDefinition
		{
		public:
			ADD_STRUCT(ScriptName, InputKeyToEmulate, 20)
			ADD_BOOL(bEmulateButtonPress, 16, 0x1)
			ADD_STRUCT(ScriptName, AdjacentAxisInputKey, 8)
			ADD_STRUCT(ScriptName, AxisInputKey, 0)
		};
		class RawInputKeyEventData
		{
		public:
			ADD_STRUCT(byte, ModifierKeyFlags, 8)
			ADD_STRUCT(ScriptName, InputKeyName, 0)
		};
		class UIProviderScriptFieldValue
		{
		public:
			ADD_STRUCT(ScriptArray<int>, ArrayValue, 28)
			ADD_STRUCT(UIRoot::TextureCoordinates, AtlasCoordinates, 68)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, NetIdValue, 60)
			ADD_STRUCT(UIRoot::UIRangeData, RangeValue, 40)
			ADD_OBJECT(Surface, ImageValue, 24)
			ADD_STRUCT(ScriptString*, StringValue, 12)
			ADD_STRUCT(UIRoot::EUIDataProviderFieldType, PropertyType, 8)
			ADD_STRUCT(ScriptName, PropertyTag, 0)
		};
		class UIProviderFieldValue : public UIProviderScriptFieldValue
		{
		public:
			ADD_STRUCT(Object::Pointer, CustomStringNode, 84)
		};
		class UIDataStoreBinding
		{
		public:
			ADD_OBJECT(UIDataStore, ResolvedDataStore, 44)
			ADD_STRUCT(ScriptName, DataStoreField, 36)
			ADD_STRUCT(ScriptName, DataStoreName, 28)
			ADD_STRUCT(int, BindingIndex, 24)
			ADD_STRUCT(ScriptString*, MarkupString, 12)
			ADD_STRUCT(UIRoot::EUIDataProviderFieldType, RequiredFieldType, 8)
		};
		bool GetDataStoreStringValue(ScriptString* InDataStoreMarkup, ScriptString*& OutStringValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetDataStoreStringValue");
			byte params[32] = { NULL };
			*(ScriptString**)&params[0] = InDataStoreMarkup;
			*(ScriptString**)&params[12] = OutStringValue;
			*(class LocalPlayer**)&params[24] = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutStringValue = *(ScriptString**)&params[12];
			return *(bool*)&params[28];
		}
		bool SetDataStoreStringValue(ScriptString* InDataStoreMarkup, ScriptString* InStringValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.SetDataStoreStringValue");
			byte params[32] = { NULL };
			*(ScriptString**)&params[0] = InDataStoreMarkup;
			*(ScriptString**)&params[12] = InStringValue;
			*(class LocalPlayer**)&params[24] = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		UIRoot::EInputPlatformType GetInputPlatformType(class LocalPlayer* OwningPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetInputPlatformType");
			byte params[5] = { NULL };
			*(class LocalPlayer**)&params[0] = OwningPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UIRoot::EInputPlatformType*)&params[4];
		}
		class UIInteraction* GetCurrentUIController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetCurrentUIController");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIInteraction**)&params[0];
		}
		class GameUISceneClient* GetSceneClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetSceneClient");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameUISceneClient**)&params[0];
		}
		class UIDataStore* StaticResolveDataStore(ScriptName DataStoreTag, class LocalPlayer* InPlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.StaticResolveDataStore");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = DataStoreTag;
			*(class LocalPlayer**)&params[8] = InPlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIDataStore**)&params[12];
		}
		bool SetDataStoreFieldValue(ScriptString* InDataStoreMarkup, UIRoot::UIProviderFieldValue& InFieldValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.SetDataStoreFieldValue");
			byte params[108] = { NULL };
			*(ScriptString**)&params[0] = InDataStoreMarkup;
			*(UIRoot::UIProviderFieldValue*)&params[12] = InFieldValue;
			*(class LocalPlayer**)&params[100] = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InFieldValue = *(UIRoot::UIProviderFieldValue*)&params[12];
			return *(bool*)&params[104];
		}
		bool GetDataStoreFieldValue(ScriptString* InDataStoreMarkup, UIRoot::UIProviderFieldValue& OutFieldValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetDataStoreFieldValue");
			byte params[108] = { NULL };
			*(ScriptString**)&params[0] = InDataStoreMarkup;
			*(UIRoot::UIProviderFieldValue*)&params[12] = OutFieldValue;
			*(class LocalPlayer**)&params[100] = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutFieldValue = *(UIRoot::UIProviderFieldValue*)&params[12];
			return *(bool*)&params[104];
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlineGameInterface()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetOnlineGameInterface");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0];
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlinePlayerInterface()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetOnlinePlayerInterface");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0];
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlinePlayerInterfaceEx()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetOnlinePlayerInterfaceEx");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
