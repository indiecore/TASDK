#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
namespace UnrealScript
{
	class OnlineCommunityContentInterface : public Interface
	{
	public:
		bool Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21409);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Exit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21411);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReadContentList(byte PlayerNum, int StartAt, int NumToRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21412);
			byte params[13] = { NULL };
			*params = PlayerNum;
			*(int*)&params[4] = StartAt;
			*(int*)&params[8] = NumToRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void OnReadContentListComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21417);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGetContentPayloadComplete(bool bWasSuccessful, OnlineSubsystem::CommunityContentFile FileDownloaded, ScriptArray<byte>& Payload)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21420);
			byte params[68] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileDownloaded;
			*(ScriptArray<byte>*)&params[56] = Payload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Payload = *(ScriptArray<byte>*)&params[56];
		}
		void OnDownloadContentComplete(bool bWasSuccessful, OnlineSubsystem::CommunityContentFile FileDownloaded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21422);
			byte params[56] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileDownloaded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUploadContentComplete(bool bWasSuccessful, OnlineSubsystem::CommunityContentFile UploadedFile)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21424);
			byte params[56] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = UploadedFile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadFriendsContentListComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21426);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentListCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21428);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentListCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21430);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetContentList(byte PlayerNum, ScriptArray<OnlineSubsystem::CommunityContentFile>& ContentFiles)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21432);
			byte params[17] = { NULL };
			*params = PlayerNum;
			*(ScriptArray<OnlineSubsystem::CommunityContentFile>*)&params[4] = ContentFiles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ContentFiles = *(ScriptArray<OnlineSubsystem::CommunityContentFile>*)&params[4];
			return *(bool*)&params[16];
		}
		bool ReadFriendsContentList(byte PlayerNum, ScriptArray<OnlineSubsystem::OnlineFriend>& Friends, int StartAt, int NumToRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21437);
			byte params[25] = { NULL };
			*params = PlayerNum;
			*(ScriptArray<OnlineSubsystem::OnlineFriend>*)&params[4] = Friends;
			*(int*)&params[16] = StartAt;
			*(int*)&params[20] = NumToRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Friends = *(ScriptArray<OnlineSubsystem::OnlineFriend>*)&params[4];
			return *(bool*)&params[24];
		}
		void AddReadFriendsContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsContentListCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21445);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadFriendsContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadFriendsContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsContentListCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21447);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadFriendsContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetFriendsContentList(byte PlayerNum, OnlineSubsystem::OnlineFriend& Friend, ScriptArray<OnlineSubsystem::CommunityContentFile>& ContentFiles)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21449);
			byte params[65] = { NULL };
			*params = PlayerNum;
			*(OnlineSubsystem::OnlineFriend*)&params[4] = Friend;
			*(ScriptArray<OnlineSubsystem::CommunityContentFile>*)&params[52] = ContentFiles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Friend = *(OnlineSubsystem::OnlineFriend*)&params[4];
			ContentFiles = *(ScriptArray<OnlineSubsystem::CommunityContentFile>*)&params[52];
			return *(bool*)&params[64];
		}
		bool UploadContent(byte PlayerNum, ScriptArray<byte>& Payload, OnlineSubsystem::CommunityContentMetadata& MetaData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21455);
			byte params[33] = { NULL };
			*params = PlayerNum;
			*(ScriptArray<byte>*)&params[4] = Payload;
			*(OnlineSubsystem::CommunityContentMetadata*)&params[16] = MetaData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Payload = *(ScriptArray<byte>*)&params[4];
			MetaData = *(OnlineSubsystem::CommunityContentMetadata*)&params[16];
			return *(bool*)&params[32];
		}
		void AddUploadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UploadContentCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21463);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UploadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearUploadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UploadContentCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21465);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UploadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DownloadContent(byte PlayerNum, OnlineSubsystem::CommunityContentFile& FileToDownload)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21467);
			byte params[57] = { NULL };
			*params = PlayerNum;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileToDownload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileToDownload = *(OnlineSubsystem::CommunityContentFile*)&params[4];
			return *(bool*)&params[56];
		}
		void AddDownloadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DownloadContentCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21473);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DownloadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearDownloadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DownloadContentCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21475);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DownloadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetContentPayload(byte PlayerNum, OnlineSubsystem::CommunityContentFile& FileDownloaded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21477);
			byte params[57] = { NULL };
			*params = PlayerNum;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileDownloaded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileDownloaded = *(OnlineSubsystem::CommunityContentFile*)&params[4];
			return *(bool*)&params[56];
		}
		void AddGetContentPayloadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GetContentPayloadCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21485);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = GetContentPayloadCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearGetContentPayloadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GetContentPayloadCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21487);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = GetContentPayloadCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RateContent(byte PlayerNum, OnlineSubsystem::CommunityContentFile& FileToRate, int NewRating)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21489);
			byte params[57] = { NULL };
			*params = PlayerNum;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileToRate;
			*(int*)&params[56] = NewRating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileToRate = *(OnlineSubsystem::CommunityContentFile*)&params[4];
		}
	};
}
