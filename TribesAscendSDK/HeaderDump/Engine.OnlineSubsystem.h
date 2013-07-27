#pragma once
#include "Core.Object.h"
#include "Engine.IniLocPatcher.h"
#include "Engine.OnlineGameSettings.h"
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
	class OnlineSubsystem : public Object
	{
	public:
		enum EOnlineNewsType : byte
		{
			ONT_Unknown = 0,
			ONT_GameNews = 1,
			ONT_ContentAnnouncements = 2,
			ONT_Misc = 3,
			ONT_MAX = 4,
		};
		enum ENATType : byte
		{
			NAT_Unknown = 0,
			NAT_Open = 1,
			NAT_Moderate = 2,
			NAT_Strict = 3,
			NAT_MAX = 4,
		};
		enum EOnlineServerConnectionStatus : byte
		{
			OSCS_NotConnected = 0,
			OSCS_Connected = 1,
			OSCS_ConnectionDropped = 2,
			OSCS_NoNetworkConnection = 3,
			OSCS_ServiceUnavailable = 4,
			OSCS_UpdateRequired = 5,
			OSCS_ServersTooBusy = 6,
			OSCS_DuplicateLoginDetected = 7,
			OSCS_InvalidUser = 8,
			OSCS_MAX = 9,
		};
		enum EOnlineEnumerationReadState : byte
		{
			OERS_NotStarted = 0,
			OERS_InProgress = 1,
			OERS_Done = 2,
			OERS_Failed = 3,
			OERS_MAX = 4,
		};
		enum EOnlineGameState : byte
		{
			OGS_NoSession = 0,
			OGS_Pending = 1,
			OGS_Starting = 2,
			OGS_InProgress = 3,
			OGS_Ending = 4,
			OGS_Ended = 5,
			OGS_MAX = 6,
		};
		enum EOnlineAccountCreateStatus : byte
		{
			OACS_CreateSuccessful = 0,
			OACS_UnknownError = 1,
			OACS_InvalidUserName = 2,
			OACS_InvalidPassword = 3,
			OACS_InvalidUniqueUserName = 4,
			OACS_UniqueUserNameInUse = 5,
			OACS_ServiceUnavailable = 6,
			OACS_MAX = 7,
		};
		enum ELanBeaconState : byte
		{
			LANB_NotUsingLanBeacon = 0,
			LANB_Hosting = 1,
			LANB_Searching = 2,
			LANB_MAX = 3,
		};
		enum EOnlineContentType : byte
		{
			OCT_Downloaded = 0,
			OCT_SaveGame = 1,
			OCT_MAX = 2,
		};
		enum EOnlineFriendState : byte
		{
			OFS_Offline = 0,
			OFS_Online = 1,
			OFS_Away = 2,
			OFS_Busy = 3,
			OFS_MAX = 4,
		};
		enum ENetworkNotificationPosition : byte
		{
			NNP_TopLeft = 0,
			NNP_TopCenter = 1,
			NNP_TopRight = 2,
			NNP_CenterLeft = 3,
			NNP_Center = 4,
			NNP_CenterRight = 5,
			NNP_BottomLeft = 6,
			NNP_BottomCenter = 7,
			NNP_BottomRight = 8,
			NNP_MAX = 9,
		};
		enum EFeaturePrivilegeLevel : byte
		{
			FPL_Disabled = 0,
			FPL_EnabledFriendsOnly = 1,
			FPL_Enabled = 2,
			FPL_MAX = 3,
		};
		enum ELoginStatus : byte
		{
			LS_NotLoggedIn = 0,
			LS_UsingLocalProfile = 1,
			LS_LoggedIn = 2,
			LS_MAX = 3,
		};
		class UniqueNetId
		{
		public:
			ADD_STRUCT(Object::QWord, Uid, 0)
		};
		class NamedInterface
		{
		public:
			ADD_OBJECT(Object, InterfaceObject, 8)
			ADD_STRUCT(ScriptName, InterfaceName, 0)
		};
		class AchievementDetails
		{
		public:
			ADD_STRUCT(int, Id, 0)
			ADD_STRUCT(ScriptString*, AchievementName, 4)
			ADD_STRUCT(ScriptString*, Description, 16)
			ADD_STRUCT(ScriptString*, HowTo, 28)
			ADD_OBJECT(Surface, Image, 40)
			ADD_STRUCT(int, GamerPoints, 44)
			ADD_BOOL(bIsSecret, 48, 0x1)
			ADD_BOOL(bWasAchievedOnline, 48, 0x2)
			ADD_BOOL(bWasAchievedOffline, 48, 0x4)
		};
		class CommunityContentMetadata
		{
		public:
			ADD_STRUCT(int, ContentType, 0)
			ADD_STRUCT(ScriptArray<Settings::SettingsProperty>, MetadataItems, 4)
		};
		class CommunityContentFile
		{
		public:
			ADD_STRUCT(int, ContentId, 0)
			ADD_STRUCT(int, FileId, 4)
			ADD_STRUCT(int, ContentType, 8)
			ADD_STRUCT(int, FileSize, 12)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, Owner, 16)
			ADD_STRUCT(int, DownloadCount, 24)
			ADD_STRUCT(float, AverageRating, 28)
			ADD_STRUCT(int, RatingCount, 32)
			ADD_STRUCT(int, LastRatingGiven, 36)
			ADD_STRUCT(ScriptString*, LocalFilePath, 40)
		};
		class NamedInterfaceDef
		{
		public:
			ADD_STRUCT(ScriptName, InterfaceName, 0)
			ADD_STRUCT(ScriptString*, InterfaceClassName, 8)
		};
		class OnlineFriendMessage
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, SendingPlayerId, 0)
			ADD_STRUCT(ScriptString*, SendingPlayerNick, 8)
			ADD_BOOL(bIsFriendInvite, 20, 0x1)
			ADD_BOOL(bIsGameInvite, 20, 0x2)
			ADD_BOOL(bWasAccepted, 20, 0x4)
			ADD_BOOL(bWasDenied, 20, 0x8)
			ADD_STRUCT(ScriptString*, Message, 24)
		};
		class RemoteTalker
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, TalkerId, 0)
			ADD_STRUCT(float, LastNotificationTime, 8)
			ADD_BOOL(bWasTalking, 12, 0x1)
			ADD_BOOL(bIsTalking, 12, 0x2)
			ADD_BOOL(bIsRegistered, 12, 0x4)
		};
		class LocalTalker
		{
		public:
			ADD_BOOL(bHasVoice, 0, 0x1)
			ADD_BOOL(bHasNetworkedVoice, 0, 0x2)
			ADD_BOOL(bIsRecognizingSpeech, 0, 0x4)
			ADD_BOOL(bWasTalking, 0, 0x8)
			ADD_BOOL(bIsTalking, 0, 0x10)
			ADD_BOOL(bIsRegistered, 0, 0x20)
		};
		class OnlinePlayerScore
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, PlayerID, 0)
			ADD_STRUCT(int, TeamID, 8)
			ADD_STRUCT(int, Score, 12)
		};
		class SpeechRecognizedWord
		{
		public:
			ADD_STRUCT(int, WordId, 0)
			ADD_STRUCT(ScriptString*, WordText, 4)
			ADD_STRUCT(float, Confidence, 16)
		};
		class FriendsQuery
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, UniqueId, 0)
			ADD_BOOL(bIsFriend, 8, 0x1)
		};
		class OnlineRegistrant
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, PlayerNetId, 0)
		};
		class OnlineArbitrationRegistrant : public OnlineRegistrant
		{
		public:
			ADD_STRUCT(Object::QWord, MachineId, 8)
			ADD_STRUCT(int, Trustworthiness, 16)
		};
		class OnlinePartyMember
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, UniqueId, 0)
			ADD_STRUCT(ScriptString*, NickName, 8)
			ADD_STRUCT(byte, LocalUserNum, 20)
			ADD_STRUCT(OnlineSubsystem::ENATType, NatType, 21)
			ADD_STRUCT(int, TitleId, 24)
			ADD_BOOL(bIsLocal, 28, 0x1)
			ADD_BOOL(bIsInPartyVoice, 28, 0x2)
			ADD_BOOL(bIsTalking, 28, 0x4)
			ADD_BOOL(bIsInGameSession, 28, 0x8)
			ADD_BOOL(bIsPlayingThisGame, 28, 0x10)
			ADD_STRUCT(Object::QWord, SessionId, 32)
			ADD_STRUCT(int, Data1, 40)
			ADD_STRUCT(int, Data2, 44)
			ADD_STRUCT(int, Data3, 48)
			ADD_STRUCT(int, Data4, 52)
		};
		class TitleFile
		{
		public:
			ADD_STRUCT(ScriptString*, Filename, 0)
			ADD_STRUCT(OnlineSubsystem::EOnlineEnumerationReadState, AsyncState, 12)
			ADD_STRUCT(ScriptArray<byte>, Data, 16)
		};
		class OnlineContent
		{
		public:
			ADD_STRUCT(OnlineSubsystem::EOnlineContentType, ContentType, 0)
			ADD_STRUCT(byte, UserIndex, 1)
			ADD_STRUCT(int, DeviceID, 4)
			ADD_STRUCT(ScriptString*, FriendlyName, 8)
			ADD_STRUCT(ScriptString*, Filename, 20)
			ADD_STRUCT(ScriptString*, ContentPath, 32)
			ADD_STRUCT(ScriptArray<ScriptString*>, ContentPackages, 44)
			ADD_STRUCT(ScriptArray<ScriptString*>, ContentFiles, 56)
		};
		class OnlineFriend
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, UniqueId, 0)
			ADD_STRUCT(Object::QWord, SessionId, 8)
			ADD_STRUCT(ScriptString*, NickName, 16)
			ADD_STRUCT(ScriptString*, PresenceInfo, 28)
			ADD_STRUCT(OnlineSubsystem::EOnlineFriendState, FriendState, 40)
			ADD_BOOL(bIsOnline, 44, 0x1)
			ADD_BOOL(bIsPlaying, 44, 0x2)
			ADD_BOOL(bIsPlayingThisGame, 44, 0x4)
			ADD_BOOL(bIsJoinable, 44, 0x8)
			ADD_BOOL(bHasVoiceSupport, 44, 0x10)
			ADD_BOOL(bHaveInvited, 44, 0x20)
			ADD_BOOL(bHasInvitedYou, 44, 0x40)
		};
		class NamedSession
		{
		public:
			ADD_OBJECT(OnlineGameSettings, GameSettings, 12)
			ADD_STRUCT(ScriptArray<OnlineSubsystem::OnlineRegistrant>, Registrants, 16)
			ADD_STRUCT(ScriptArray<OnlineSubsystem::OnlineArbitrationRegistrant>, ArbitrationRegistrants, 28)
			ADD_STRUCT(ScriptName, SessionName, 0)
			ADD_STRUCT(Object::Pointer, SessionInfo, 8)
		};
		ADD_STRUCT(ScriptArray<OnlineSubsystem::NamedSession>, Sessions, 184)
		ADD_STRUCT(Object::Pointer, VfTable_FTickableObject, 60)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::NamedInterface>, NamedInterfaces, 160)
		ADD_STRUCT(ScriptString*, IniLocPatcherClassName, 204)
		ADD_OBJECT(IniLocPatcher, Patcher, 216)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::NamedInterfaceDef>, NamedInterfaceDefs, 172)
		ADD_BOOL(bUseBuildIdOverride, 196, 0x1)
		ADD_STRUCT(int, BuildIdOverride, 200)
		ADD_STRUCT(float, AsyncMinCompletionTime, 220)
		void SetDebugSpewLevel(int DebugSpewLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetDebugSpewLevel");
			byte params[4] = { NULL };
			*(int*)&params[0] = DebugSpewLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DumpVoiceRegistration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.DumpVoiceRegistration");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpSessionState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.DumpSessionState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpGameSettings(class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.DumpGameSettings");
			byte params[4] = { NULL };
			*(class OnlineGameSettings**)&params[0] = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumSupportedLogins()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.GetNumSupportedLogins");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetBuildUniqueId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.GetBuildUniqueId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool StringToUniqueNetId(ScriptString* UniqueNetIdString, OnlineSubsystem::UniqueNetId& out_UniqueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.StringToUniqueNetId");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = UniqueNetIdString;
			*(OnlineSubsystem::UniqueNetId*)&params[12] = out_UniqueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_UniqueId = *(OnlineSubsystem::UniqueNetId*)&params[12];
			return *(bool*)&params[20];
		}
		ScriptString* UniqueNetIdToString(OnlineSubsystem::UniqueNetId& IdToConvert)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.UniqueNetIdToString");
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = IdToConvert;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			IdToConvert = *(OnlineSubsystem::UniqueNetId*)&params[0];
			return *(ScriptString**)&params[8];
		}
		class Object* GetNamedInterface(ScriptName InterfaceName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.GetNamedInterface");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InterfaceName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)&params[8];
		}
		void SetNamedInterface(ScriptName InterfaceName, class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetNamedInterface");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InterfaceName;
			*(class Object**)&params[8] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetGameChatInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetGameChatInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetTitleFileInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetTitleFileInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetPartyChatInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetPartyChatInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetNewsInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetNewsInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetStatsInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetStatsInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetVoiceInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetVoiceInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetContentInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetContentInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetGameInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetGameInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetSystemInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetSystemInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetPlayerInterfaceEx(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetPlayerInterfaceEx");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetPlayerInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetPlayerInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetAccountInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetAccountInterface");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Exit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.Exit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PostInit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.PostInit");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.Init");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
