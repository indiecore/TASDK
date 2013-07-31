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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21494);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnWriteSaveGameDataComplete(bool bWasSuccessful, byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21496);
			byte params[45] = { NULL };
			*(bool*)params = bWasSuccessful;
			params[4] = LocalUserNum;
			*(int*)&params[8] = DeviceID;
			*(ScriptString**)&params[12] = FriendlyName;
			*(ScriptString**)&params[24] = Filename;
			*(ScriptString**)&params[36] = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadSaveGameDataComplete(bool bWasSuccessful, byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21498);
			byte params[45] = { NULL };
			*(bool*)params = bWasSuccessful;
			params[4] = LocalUserNum;
			*(int*)&params[8] = DeviceID;
			*(ScriptString**)&params[12] = FriendlyName;
			*(ScriptString**)&params[24] = Filename;
			*(ScriptString**)&params[36] = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnQueryAvailableDownloadsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21500);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadContentComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21502);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddContentChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ContentDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21504);
			byte params[13] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ContentDelegate;
			params[12] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearContentChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ContentDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21507);
			byte params[13] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ContentDelegate;
			params[12] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadContentComplete(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21511);
			byte params[14] = { NULL };
			*params = LocalUserNum;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21515);
			byte params[14] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadContentList(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType, int DeviceID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21519);
			byte params[10] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			*(int*)&params[4] = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ClearContentList(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21524);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetContentList(byte LocalUserNum, OnlineSubsystem::EOnlineContentType ContentType, ScriptArray<OnlineSubsystem::OnlineContent>& ContentList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21527);
			byte params[15] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineContentType*)&params[1] = ContentType;
			*(ScriptArray<OnlineSubsystem::OnlineContent>*)&params[4] = ContentList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ContentList = *(ScriptArray<OnlineSubsystem::OnlineContent>*)&params[4];
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[16];
		}
		bool QueryAvailableDownloads(byte LocalUserNum, int CategoryMask)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21533);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = CategoryMask;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddQueryAvailableDownloadsComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QueryDownloadsDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21538);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = QueryDownloadsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQueryAvailableDownloadsComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QueryDownloadsDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21541);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = QueryDownloadsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetAvailableDownloadCounts(byte LocalUserNum, int& NewDownloads, int& TotalDownloads)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21544);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = NewDownloads;
			*(int*)&params[8] = TotalDownloads;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewDownloads = *(int*)&params[4];
			TotalDownloads = *(int*)&params[8];
		}
		bool ReadSaveGameData(byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21548);
			byte params[45] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = DeviceID;
			*(ScriptString**)&params[8] = FriendlyName;
			*(ScriptString**)&params[20] = Filename;
			*(ScriptString**)&params[32] = SaveFileName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[44];
		}
		bool GetSaveGameData(byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName, ScriptArray<byte>& SaveGameData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21555);
			byte params[57] = { NULL };
			*params = LocalUserNum;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21570);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21573);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WriteSaveGameData(byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename, ScriptString* SaveFileName, ScriptArray<byte>& SaveGameData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21576);
			byte params[57] = { NULL };
			*params = LocalUserNum;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21591);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WriteSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWriteSaveGameDataComplete(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteSaveGameDataCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21594);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WriteSaveGameDataCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DeleteSaveGame(byte LocalUserNum, int DeviceID, ScriptString* FriendlyName, ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21597);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = DeviceID;
			*(ScriptString**)&params[8] = FriendlyName;
			*(ScriptString**)&params[20] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		bool ClearSaveGames(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21603);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
