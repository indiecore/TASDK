#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
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
		void OnWriteSaveGameDataComplete(bool bWasSuccessful, byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnWriteSaveGameDataComplete");
			byte params[45] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			params[4] = LocalUserNum;
			*(int*)&params[8] = DeviceID;
			*(ScriptString**)&params[12] = FriendlyName;
			*(ScriptString**)&params[24] = Filename;
			*(ScriptString**)&params[36] = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadSaveGameDataComplete(bool bWasSuccessful, byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnReadSaveGameDataComplete");
			byte params[45] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			params[4] = LocalUserNum;
			*(int*)&params[8] = DeviceID;
			*(ScriptString**)&params[12] = FriendlyName;
			*(ScriptString**)&params[24] = Filename;
			*(ScriptString**)&params[36] = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnQueryAvailableDownloadsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnQueryAvailableDownloadsComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadContentComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.OnReadContentComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddContentChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ContentDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddContentChangeDelegate");
			byte params[13] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ContentDelegate;
			params[12] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearContentChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ContentDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearContentChangeDelegate");
			byte params[13] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ContentDelegate;
			params[12] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadContentComplete(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddReadContentComplete");
			byte params[14] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadContentComplete(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearReadContentComplete");
			byte params[14] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadContentList(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType, int DeviceID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ReadContentList");
			byte params[10] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			*(int*)&params[4] = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ClearContentList(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearContentList");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetContentList(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType, ScriptArray<OnlineSubsystem::OnlineContent>& ContentList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.GetContentList");
			byte params[15] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			*(ScriptArray<OnlineSubsystem::OnlineContent>*)&params[4] = ContentList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ContentList = *(ScriptArray<OnlineSubsystem::OnlineContent>*)&params[4];
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[16];
		}
		bool QueryAvailableDownloads(byte LocalUserNum, int CategoryMask)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.QueryAvailableDownloads");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = CategoryMask;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddQueryAvailableDownloadsComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QueryDownloadsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddQueryAvailableDownloadsComplete");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = QueryDownloadsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQueryAvailableDownloadsComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QueryDownloadsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearQueryAvailableDownloadsComplete");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = QueryDownloadsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetAvailableDownloadCounts(byte LocalUserNum, int& NewDownloads, int& TotalDownloads)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.GetAvailableDownloadCounts");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = NewDownloads;
			*(int*)&params[8] = TotalDownloads;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewDownloads = *(int*)&params[4];
			TotalDownloads = *(int*)&params[8];
		}
		bool ReadSaveGameData(byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ReadSaveGameData");
			byte params[45] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = DeviceID;
			*(ScriptString**)&params[8] = FriendlyName;
			*(ScriptString**)&params[20] = Filename;
			*(ScriptString**)&params[32] = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[44];
		}
		bool GetSaveGameData(byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName, ScriptArray<byte>& SaveGameData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.GetSaveGameData");
			byte params[57] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = DeviceID;
			*(ScriptString**)&params[8] = FriendlyName;
			*(ScriptString**)&params[20] = Filename;
			*(ScriptString**)&params[32] = SaveFileName;
			*(ScriptArray<byte>*)&params[44] = SaveGameData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SaveGameData = *(ScriptArray<byte>*)&params[44];
			return *(bool*)&params[56];
		}
		void AddReadSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddReadSaveGameDataComplete");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearReadSaveGameDataComplete");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WriteSaveGameData(byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName, ScriptArray<byte>& SaveGameData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.WriteSaveGameData");
			byte params[57] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = DeviceID;
			*(ScriptString**)&params[8] = FriendlyName;
			*(ScriptString**)&params[20] = Filename;
			*(ScriptString**)&params[32] = SaveFileName;
			*(ScriptArray<byte>*)&params[44] = SaveGameData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SaveGameData = *(ScriptArray<byte>*)&params[44];
			return *(bool*)&params[56];
		}
		void AddWriteSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.AddWriteSaveGameDataComplete");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WriteSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWriteSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearWriteSaveGameDataComplete");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WriteSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DeleteSaveGame(byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.DeleteSaveGame");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = DeviceID;
			*(ScriptString**)&params[8] = FriendlyName;
			*(ScriptString**)&params[20] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		bool ClearSaveGames(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineContentInterface.ClearSaveGames");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
