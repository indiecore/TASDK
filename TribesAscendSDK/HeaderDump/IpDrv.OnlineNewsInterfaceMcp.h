#pragma once
#include "IpDrv.MCPBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineNewsInterfaceMcp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineNewsInterfaceMcp : public MCPBase
	{
	public:
		ADD_VAR(::BoolProperty, bNeedsTicking, 0x1)
		void OnReadNewsCompleted(bool bWasSuccessful, byte NewsType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineNewsInterfaceMcp.OnReadNewsCompleted");
			byte* params = (byte*)malloc(5);
			*(bool*)params = bWasSuccessful;
			*(params + 4) = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadNews(byte LocalUserNum, byte NewsType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineNewsInterfaceMcp.ReadNews");
			byte* params = (byte*)malloc(6);
			*params = LocalUserNum;
			*(params + 1) = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadNewsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineNewsInterfaceMcp.AddReadNewsCompletedDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadGameNewsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineNewsInterfaceMcp.ClearReadNewsCompletedDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadGameNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetNews(byte LocalUserNum, byte NewsType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineNewsInterfaceMcp.GetNews");
			byte* params = (byte*)malloc(14);
			*params = LocalUserNum;
			*(params + 1) = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
