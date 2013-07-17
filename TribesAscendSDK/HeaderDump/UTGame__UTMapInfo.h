#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTMapInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTMapInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTMapInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTMapInfo : public UDKMapInfo
	{
	public:
			ADD_OBJECT( Texture, MapTexture )
			ADD_STRUCT( ::VectorProperty, MapCenter, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MapExtent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MapScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RecommendedPlayersMax, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RecommendedPlayersMin, 0xFFFFFFFF )
			ADD_OBJECT( UDKVehicle, KeyVehicles )
			ADD_OBJECT( MaterialInstanceConstant, GreenIconMaterialInstance )
			ADD_VAR( ::FloatProperty, ColorPercent, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CenterPos, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadarRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadarWidth, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ActualMapCenter, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UseableRadius, 0xFFFFFFFF )
			ADD_OBJECT( Material, MapMaterialReference )
			ADD_OBJECT( MaterialInstanceConstant, MapMaterialInstance )
			ADD_VAR( ::IntProperty, CurrentMapRotYaw, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MapRotY, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MapRotX, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, HUDIconsT )
			ADD_OBJECT( Material, HudIcons )
			ADD_OBJECT( Actor, WatchedActor )
			ADD_OBJECT( Actor, CurrentActor )
			ADD_VAR( ::BoolProperty, bMapUpToDate, 0x1 )
			ADD_VAR( ::FloatProperty, DefaultMapSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotatingMiniMapRange, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MapYaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MapTextureYaw, 0xFFFFFFFF )
			ADD_OBJECT( UTMapMusicInfo, MapMusicInfo )
			void VerifyMapExtent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.VerifyMapExtent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindObjectives(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.FindObjectives" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderLinks( class Canvas* Canvas, class UTPlayerController* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.RenderLinks" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( class UTPlayerController** )( params + 4 ) = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderAdditionalInformation( class Canvas* Canvas, class UTPlayerController* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.RenderAdditionalInformation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( class UTPlayerController** )( params + 4 ) = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateNodes( class UTPlayerController* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.UpdateNodes" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )( params + 0 ) = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMap( class Canvas* Canvas, class UTPlayerController* PlayerOwner, float XPos, float YPos, float Width, float Height, bool bFullDetail, float AspectRatio )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.DrawMap" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( class UTPlayerController** )( params + 4 ) = PlayerOwner;
				*( float* )( params + 8 ) = XPos;
				*( float* )( params + 12 ) = YPos;
				*( float* )( params + 16 ) = Width;
				*( float* )( params + 20 ) = Height;
				*( bool* )( params + 24 ) = bFullDetail;
				*( float* )( params + 28 ) = AspectRatio;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddKeyVehicle( class UTVehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.AddKeyVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTVehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawRotatedTile( class Canvas* Canvas, class Texture2D* T, Vector MapLocation, int InYaw, float IconScale, void* TexCoords, void* DrawColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.DrawRotatedTile" );
				byte *params = ( byte* )( malloc( 60 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( class Texture2D** )( params + 4 ) = T;
				*( Vector* )( params + 8 ) = MapLocation;
				*( int* )( params + 20 ) = InYaw;
				*( float* )( params + 24 ) = IconScale;
				*( void** )( params + 28 ) = TexCoords;
				*( void** )( params + 44 ) = DrawColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawRotatedMaterialTile( class Canvas* Canvas, class MaterialInstanceConstant* M, Vector MapLocation, int InYaw, float XWidth, float YWidth, float XStart, float YStart, float XLength, float YLength )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.DrawRotatedMaterialTile" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( class MaterialInstanceConstant** )( params + 4 ) = M;
				*( Vector* )( params + 8 ) = MapLocation;
				*( int* )( params + 20 ) = InYaw;
				*( float* )( params + 24 ) = XWidth;
				*( float* )( params + 28 ) = YWidth;
				*( float* )( params + 32 ) = XStart;
				*( float* )( params + 36 ) = YStart;
				*( float* )( params + 40 ) = XLength;
				*( float* )( params + 44 ) = YLength;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector UpdateHUDLocation( Vector InLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.UpdateHUDLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = InLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void ChangeMapRotation( Rotator NewMapRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.ChangeMapRotation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = NewMapRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMapImage( class Canvas* Canvas, float X, float Y, float W, float H, float PlayerYaw, float BkgImgScaling )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.DrawMapImage" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( float* )( params + 4 ) = X;
				*( float* )( params + 8 ) = Y;
				*( float* )( params + 12 ) = W;
				*( float* )( params + 16 ) = H;
				*( float* )( params + 20 ) = PlayerYaw;
				*( float* )( params + 24 ) = BkgImgScaling;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetActorHudLocation( class Actor* CActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTMapInfo.GetActorHudLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = CActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
