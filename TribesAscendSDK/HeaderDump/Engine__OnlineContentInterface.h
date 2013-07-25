#pragma once
#include "Core__Interface.h"
namespace UnrealScript
{
	class OnlineContentInterface : public Interface
	{
	public:
		void OnContentChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnContentChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnWriteSaveGameDataComplete(bool bWasSuccessful, byte LocalUserNum, int DeviceID, ScriptArray<wchar_t> FriendlyName, ScriptArray<wchar_t> Filename, ScriptArray<wchar_t> SaveFileName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnWriteSaveGameDataComplete");
			byte* params = (byte*)malloc(45);
			*(bool*)params = bWasSuccessful;
			*(params + 4) = LocalUserNum;
			*(int*)(params + 8) = DeviceID;
			*(ScriptArray<wchar_t>*)(params + 12) = FriendlyName;
			*(ScriptArray<wchar_t>*)(params + 24) = Filename;
			*(ScriptArray<wchar_t>*)(params + 36) = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadSaveGameDataComplete(bool bWasSuccessful, byte LocalUserNum, int DeviceID, ScriptArray<wchar_t> FriendlyName, ScriptArray<wchar_t> Filename, ScriptArray<wchar_t> SaveFileName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnReadSaveGameDataComplete");
			byte* params = (byte*)malloc(45);
			*(bool*)params = bWasSuccessful;
			*(params + 4) = LocalUserNum;
			*(int*)(params + 8) = DeviceID;
			*(ScriptArray<wchar_t>*)(params + 12) = FriendlyName;
			*(ScriptArray<wchar_t>*)(params + 24) = Filename;
			*(ScriptArray<wchar_t>*)(params + 36) = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnQueryAvailableDownloadsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnQueryAvailableDownloadsComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadContentComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnReadContentComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddContentChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ContentDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddContentChangeDelegate");
			byte* params = (byte*)malloc(13);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ContentDelegate;
			*(params + 12) = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearContentChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ContentDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearContentChangeDelegate");
			byte* params = (byte*)malloc(13);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ContentDelegate;
			*(params + 12) = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddReadContentComplete(byte LocalUserNum, byte ContentType, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddReadContentComplete");
			byte* params = (byte*)malloc(14);
			*params = LocalUserNum;
			*(params + 1) = ContentType;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadContentComplete(byte LocalUserNum, byte ContentType, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearReadContentComplete");
			byte* params = (byte*)malloc(14);
			*params = LocalUserNum;
			*(params + 1) = ContentType;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadContentList(byte LocalUserNum, byte ContentType, int DeviceID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ReadContentList");
			byte* params = (byte*)malloc(10);
			*params = LocalUserNum;
			*(params + 1) = ContentType;
			*(int*)(params + 4) = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void ClearContentList(byte LocalUserNum, byte ContentType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearContentList");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			*(params + 1) = ContentType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetContentList(byte LocalUserNum, byte ContentType, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ContentList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.GetContentList");
			byte* params = (byte*)malloc(15);
			*params = LocalUserNum;
			*(params + 1) = ContentType;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ContentList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ContentList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(params + 16);
			free(params);
			return returnVal;
		}
		bool QueryAvailableDownloads(byte LocalUserNum, int CategoryMask)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.QueryAvailableDownloads");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = CategoryMask;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddQueryAvailableDownloadsComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QueryDownloadsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddQueryAvailableDownloadsComplete");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = QueryDownloadsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearQueryAvailableDownloadsComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QueryDownloadsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearQueryAvailableDownloadsComplete");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = QueryDownloadsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetAvailableDownloadCounts(byte LocalUserNum, int& NewDownloads, int& TotalDownloads)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.GetAvailableDownloadCounts");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = NewDownloads;
			*(int*)(params + 8) = TotalDownloads;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewDownloads = *(int*)(params + 4);
			TotalDownloads = *(int*)(params + 8);
			free(params);
		}
		bool ReadSaveGameData(byte LocalUserNum, int DeviceID, ScriptArray<wchar_t> FriendlyName, ScriptArray<wchar_t> Filename, ScriptArray<wchar_t> SaveFileName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ReadSaveGameData");
			byte* params = (byte*)malloc(45);
			*params = LocalUserNum;
			*(int*)(params + 4) = DeviceID;
			*(ScriptArray<wchar_t>*)(params + 8) = FriendlyName;
			*(ScriptArray<wchar_t>*)(params + 20) = Filename;
			*(ScriptArray<wchar_t>*)(params + 32) = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 44);
			free(params);
			return returnVal;
		}
		bool GetSaveGameData(byte LocalUserNum, int DeviceID, ScriptArray<wchar_t> FriendlyName, ScriptArray<wchar_t> Filename, ScriptArray<wchar_t> SaveFileName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& SaveGameData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.GetSaveGameData");
			byte* params = (byte*)malloc(57);
			*params = LocalUserNum;
			*(int*)(params + 4) = DeviceID;
			*(ScriptArray<wchar_t>*)(params + 8) = FriendlyName;
			*(ScriptArray<wchar_t>*)(params + 20) = Filename;
			*(ScriptArray<wchar_t>*)(params + 32) = SaveFileName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 44) = SaveGameData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SaveGameData = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 44);
			auto returnVal = *(bool*)(params + 56);
			free(params);
			return returnVal;
		}
		void AddReadSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddReadSaveGameDataComplete");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearReadSaveGameDataComplete");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool WriteSaveGameData(byte LocalUserNum, int DeviceID, ScriptArray<wchar_t> FriendlyName, ScriptArray<wchar_t> Filename, ScriptArray<wchar_t> SaveFileName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& SaveGameData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.WriteSaveGameData");
			byte* params = (byte*)malloc(57);
			*params = LocalUserNum;
			*(int*)(params + 4) = DeviceID;
			*(ScriptArray<wchar_t>*)(params + 8) = FriendlyName;
			*(ScriptArray<wchar_t>*)(params + 20) = Filename;
			*(ScriptArray<wchar_t>*)(params + 32) = SaveFileName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 44) = SaveGameData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SaveGameData = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 44);
			auto returnVal = *(bool*)(params + 56);
			free(params);
			return returnVal;
		}
		void AddWriteSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddWriteSaveGameDataComplete");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = WriteSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearWriteSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearWriteSaveGameDataComplete");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = WriteSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DeleteSaveGame(byte LocalUserNum, int DeviceID, ScriptArray<wchar_t> FriendlyName, ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.DeleteSaveGame");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(int*)(params + 4) = DeviceID;
			*(ScriptArray<wchar_t>*)(params + 8) = FriendlyName;
			*(ScriptArray<wchar_t>*)(params + 20) = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		bool ClearSaveGames(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearSaveGames");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
