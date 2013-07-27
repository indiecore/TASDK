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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.Init");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Exit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.Exit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReadContentList(byte PlayerNum, int StartAt, int NumToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ReadContentList");
			byte params[13] = { NULL };
			params[0] = PlayerNum;
			*(int*)&params[4] = StartAt;
			*(int*)&params[8] = NumToRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void OnReadContentListComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnReadContentListComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGetContentPayloadComplete(bool bWasSuccessful, OnlineSubsystem::CommunityContentFile FileDownloaded, ScriptArray<byte>& Payload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnGetContentPayloadComplete");
			byte params[68] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileDownloaded;
			*(ScriptArray<byte>*)&params[56] = Payload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Payload = *(ScriptArray<byte>*)&params[56];
		}
		void OnDownloadContentComplete(bool bWasSuccessful, OnlineSubsystem::CommunityContentFile FileDownloaded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnDownloadContentComplete");
			byte params[56] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileDownloaded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUploadContentComplete(bool bWasSuccessful, OnlineSubsystem::CommunityContentFile UploadedFile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnUploadContentComplete");
			byte params[56] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = UploadedFile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadFriendsContentListComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnReadFriendsContentListComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentListCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddReadContentListCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentListCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearReadContentListCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetContentList(byte PlayerNum, ScriptArray<OnlineSubsystem::CommunityContentFile>& ContentFiles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.GetContentList");
			byte params[17] = { NULL };
			params[0] = PlayerNum;
			*(ScriptArray<OnlineSubsystem::CommunityContentFile>*)&params[4] = ContentFiles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ContentFiles = *(ScriptArray<OnlineSubsystem::CommunityContentFile>*)&params[4];
			return *(bool*)&params[16];
		}
		bool ReadFriendsContentList(byte PlayerNum, ScriptArray<OnlineSubsystem::OnlineFriend>& Friends, int StartAt, int NumToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ReadFriendsContentList");
			byte params[25] = { NULL };
			params[0] = PlayerNum;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddReadFriendsContentListCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadFriendsContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadFriendsContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsContentListCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearReadFriendsContentListCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadFriendsContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetFriendsContentList(byte PlayerNum, OnlineSubsystem::OnlineFriend& Friend, ScriptArray<OnlineSubsystem::CommunityContentFile>& ContentFiles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.GetFriendsContentList");
			byte params[65] = { NULL };
			params[0] = PlayerNum;
			*(OnlineSubsystem::OnlineFriend*)&params[4] = Friend;
			*(ScriptArray<OnlineSubsystem::CommunityContentFile>*)&params[52] = ContentFiles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Friend = *(OnlineSubsystem::OnlineFriend*)&params[4];
			ContentFiles = *(ScriptArray<OnlineSubsystem::CommunityContentFile>*)&params[52];
			return *(bool*)&params[64];
		}
		bool UploadContent(byte PlayerNum, ScriptArray<byte>& Payload, OnlineSubsystem::CommunityContentMetadata& MetaData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.UploadContent");
			byte params[33] = { NULL };
			params[0] = PlayerNum;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddUploadContentCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = UploadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearUploadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UploadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearUploadContentCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = UploadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DownloadContent(byte PlayerNum, OnlineSubsystem::CommunityContentFile& FileToDownload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.DownloadContent");
			byte params[57] = { NULL };
			params[0] = PlayerNum;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileToDownload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileToDownload = *(OnlineSubsystem::CommunityContentFile*)&params[4];
			return *(bool*)&params[56];
		}
		void AddDownloadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DownloadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddDownloadContentCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = DownloadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearDownloadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DownloadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearDownloadContentCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = DownloadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetContentPayload(byte PlayerNum, OnlineSubsystem::CommunityContentFile& FileDownloaded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.GetContentPayload");
			byte params[57] = { NULL };
			params[0] = PlayerNum;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileDownloaded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileDownloaded = *(OnlineSubsystem::CommunityContentFile*)&params[4];
			return *(bool*)&params[56];
		}
		void AddGetContentPayloadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GetContentPayloadCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddGetContentPayloadCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = GetContentPayloadCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearGetContentPayloadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GetContentPayloadCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearGetContentPayloadCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = GetContentPayloadCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RateContent(byte PlayerNum, OnlineSubsystem::CommunityContentFile& FileToRate, int NewRating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.RateContent");
			byte params[57] = { NULL };
			params[0] = PlayerNum;
			*(OnlineSubsystem::CommunityContentFile*)&params[4] = FileToRate;
			*(int*)&params[56] = NewRating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileToRate = *(OnlineSubsystem::CommunityContentFile*)&params[4];
		}
	};
}
