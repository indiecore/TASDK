#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.CommunityContentFile.h"
#include "Engine.OnlineSubsystem.OnlineFriend.h"
#include "Engine.OnlineSubsystem.CommunityContentMetadata.h"
namespace UnrealScript
{
	class OnlineCommunityContentInterface : public Interface
	{
	public:
		bool Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.Init");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Exit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.Exit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReadContentList(byte PlayerNum, int StartAt, int NumToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ReadContentList");
			byte* params = (byte*)malloc(13);
			*params = PlayerNum;
			*(int*)(params + 4) = StartAt;
			*(int*)(params + 8) = NumToRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnReadContentListComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnReadContentListComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGetContentPayloadComplete(bool bWasSuccessful, CommunityContentFile FileDownloaded, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Payload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnGetContentPayloadComplete");
			byte* params = (byte*)malloc(68);
			*(bool*)params = bWasSuccessful;
			*(CommunityContentFile*)(params + 4) = FileDownloaded;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 56) = Payload;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Payload = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 56);
			free(params);
		}
		void OnDownloadContentComplete(bool bWasSuccessful, CommunityContentFile FileDownloaded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnDownloadContentComplete");
			byte* params = (byte*)malloc(56);
			*(bool*)params = bWasSuccessful;
			*(CommunityContentFile*)(params + 4) = FileDownloaded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUploadContentComplete(bool bWasSuccessful, CommunityContentFile UploadedFile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnUploadContentComplete");
			byte* params = (byte*)malloc(56);
			*(bool*)params = bWasSuccessful;
			*(CommunityContentFile*)(params + 4) = UploadedFile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadFriendsContentListComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.OnReadFriendsContentListComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddReadContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentListCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddReadContentListCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadContentListCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearReadContentListCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetContentList(byte PlayerNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ContentFiles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.GetContentList");
			byte* params = (byte*)malloc(17);
			*params = PlayerNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ContentFiles;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ContentFiles = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool ReadFriendsContentList(byte PlayerNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Friends, int StartAt, int NumToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ReadFriendsContentList");
			byte* params = (byte*)malloc(25);
			*params = PlayerNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Friends;
			*(int*)(params + 16) = StartAt;
			*(int*)(params + 20) = NumToRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Friends = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void AddReadFriendsContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsContentListCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddReadFriendsContentListCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadFriendsContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadFriendsContentListCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsContentListCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearReadFriendsContentListCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadFriendsContentListCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetFriendsContentList(byte PlayerNum, OnlineFriend& Friend, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ContentFiles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.GetFriendsContentList");
			byte* params = (byte*)malloc(65);
			*params = PlayerNum;
			*(OnlineFriend*)(params + 4) = Friend;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 52) = ContentFiles;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Friend = *(OnlineFriend*)(params + 4);
			ContentFiles = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 52);
			auto returnVal = *(bool*)(params + 64);
			free(params);
			return returnVal;
		}
		bool UploadContent(byte PlayerNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Payload, CommunityContentMetadata& MetaData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.UploadContent");
			byte* params = (byte*)malloc(33);
			*params = PlayerNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Payload;
			*(CommunityContentMetadata*)(params + 16) = MetaData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Payload = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			MetaData = *(CommunityContentMetadata*)(params + 16);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void AddUploadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UploadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddUploadContentCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UploadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearUploadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UploadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearUploadContentCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UploadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DownloadContent(byte PlayerNum, CommunityContentFile& FileToDownload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.DownloadContent");
			byte* params = (byte*)malloc(57);
			*params = PlayerNum;
			*(CommunityContentFile*)(params + 4) = FileToDownload;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FileToDownload = *(CommunityContentFile*)(params + 4);
			auto returnVal = *(bool*)(params + 56);
			free(params);
			return returnVal;
		}
		void AddDownloadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DownloadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddDownloadContentCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DownloadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearDownloadContentCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DownloadContentCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearDownloadContentCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DownloadContentCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetContentPayload(byte PlayerNum, CommunityContentFile& FileDownloaded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.GetContentPayload");
			byte* params = (byte*)malloc(57);
			*params = PlayerNum;
			*(CommunityContentFile*)(params + 4) = FileDownloaded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FileDownloaded = *(CommunityContentFile*)(params + 4);
			auto returnVal = *(bool*)(params + 56);
			free(params);
			return returnVal;
		}
		void AddGetContentPayloadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GetContentPayloadCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.AddGetContentPayloadCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = GetContentPayloadCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearGetContentPayloadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GetContentPayloadCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.ClearGetContentPayloadCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = GetContentPayloadCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RateContent(byte PlayerNum, CommunityContentFile& FileToRate, int NewRating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineCommunityContentInterface.RateContent");
			byte* params = (byte*)malloc(57);
			*params = PlayerNum;
			*(CommunityContentFile*)(params + 4) = FileToRate;
			*(int*)(params + 56) = NewRating;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FileToRate = *(CommunityContentFile*)(params + 4);
			free(params);
		}
	};
}
