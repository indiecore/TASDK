#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Actor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Actor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Actor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Actor : public Object
	{
	public:
			void ForceUpdateComponents( bool bCollisionUpdate, bool bTransformOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ForceUpdateComponents" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bCollisionUpdate;
				*( bool* )( params + 4 ) = bTransformOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > ConsoleCommand( ScriptArray< wchar_t > Command, bool bWriteToLog )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ConsoleCommand" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Command;
				*( bool* )( params + 12 ) = bWriteToLog;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void Sleep( float Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Sleep" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishAnim( class AnimNodeSequence* SeqNode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FinishAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNodeSequence** )params = SeqNode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCollision( bool bNewColActors, bool bNewBlockActors, bool bNewIgnoreEncroachers )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetCollision" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )params = bNewColActors;
				*( bool* )( params + 4 ) = bNewBlockActors;
				*( bool* )( params + 8 ) = bNewIgnoreEncroachers;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCollisionSize( float NewRadius, float NewHeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetCollisionSize" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = NewRadius;
				*( float* )( params + 4 ) = NewHeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCollisionType( byte NewCollisionType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetCollisionType" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = NewCollisionType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDrawScale( float NewScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetDrawScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDrawScale3D( Vector NewScale3D )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetDrawScale3D" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewScale3D;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Move( Vector Delta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Move" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = Delta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetLocation( Vector NewLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetRotation( Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetRotation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )params = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte MovingWhichWay( float &Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.MovingWhichWay" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Amount = *( float* )params;
				return *( byte* )( params + function->return_val_offset() );
			}

			void SetZone( bool bForceRefresh )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetZone" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForceRefresh;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetRelativeRotation( Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetRelativeRotation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )params = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetRelativeLocation( Vector NewLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetRelativeLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetHardAttach( bool bNewHardAttach )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetHardAttach" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewHardAttach;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int fixedTurn( int Current, int Desired, int DeltaRate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.fixedTurn" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = Current;
				*( int* )( params + 4 ) = Desired;
				*( int* )( params + 8 ) = DeltaRate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool MoveSmooth( Vector Delta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.MoveSmooth" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = Delta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AutonomousPhysics( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.AutonomousPhysics" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetTerminalVelocity(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetTerminalVelocity" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetBase( class Actor* NewBase, Vector NewFloor, ScriptName AttachName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetBase" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )params = NewBase;
				*( Vector* )( params + 4 ) = NewFloor;
				*( ScriptName* )( params + 20 ) = AttachName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOwner( class Actor* NewOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetOwner" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = NewOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindBase(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FindBase" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsBasedOn( class Actor* TestActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsBasedOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = TestActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Actor* GetBaseMost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetBaseMost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool IsOwnedBy( class Actor* TestActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsOwnedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = TestActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector GetAggregateBaseVelocity( class Actor* TestBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetAggregateBaseVelocity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = TestBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetForcedInitialReplicatedProperty( class Property* PropToReplicate, bool bAdd )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetForcedInitialReplicatedProperty" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Property** )params = PropToReplicate;
				*( bool* )( params + 4 ) = bAdd;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Vect2BP( void* &BP, Vector pos, class Actor* ForcedBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Vect2BP" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( void** )params = BP;
				*( Vector* )( params + 52 ) = pos;
				*( class Actor** )( params + 64 ) = ForcedBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BP = *( void** )params;
			}

			Vector BP2Vect( void* BP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.BP2Vect" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( void** )params = BP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void SetBasedPosition( void* &BP, Vector pos, class Actor* ForcedBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetBasedPosition" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( void** )params = BP;
				*( Vector* )( params + 52 ) = pos;
				*( class Actor** )( params + 64 ) = ForcedBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BP = *( void** )params;
			}

			Vector GetBasedPosition( void* BP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetBasedPosition" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( void** )params = BP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void FlushPersistentDebugLines(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FlushPersistentDebugLines" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugLine( Vector LineStart, Vector LineEnd, byte R, byte G, byte B, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugLine" );
				byte *params = ( byte* )( malloc( 31 ) );
				*( Vector* )params = LineStart;
				*( Vector* )( params + 12 ) = LineEnd;
				*( byte* )( params + 24 ) = R;
				*( byte* )( params + 25 ) = G;
				*( byte* )( params + 26 ) = B;
				*( bool* )( params + 28 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugPoint( Vector Position, float Size, void* PointColor, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugPoint" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )params = Position;
				*( float* )( params + 12 ) = Size;
				*( void** )( params + 16 ) = PointColor;
				*( bool* )( params + 32 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugBox( Vector Center, Vector Extent, byte R, byte G, byte B, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugBox" );
				byte *params = ( byte* )( malloc( 31 ) );
				*( Vector* )params = Center;
				*( Vector* )( params + 12 ) = Extent;
				*( byte* )( params + 24 ) = R;
				*( byte* )( params + 25 ) = G;
				*( byte* )( params + 26 ) = B;
				*( bool* )( params + 28 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugStar( Vector Position, float Size, byte R, byte G, byte B, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugStar" );
				byte *params = ( byte* )( malloc( 23 ) );
				*( Vector* )params = Position;
				*( float* )( params + 12 ) = Size;
				*( byte* )( params + 16 ) = R;
				*( byte* )( params + 17 ) = G;
				*( byte* )( params + 18 ) = B;
				*( bool* )( params + 20 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugCoordinateSystem( Vector AxisLoc, Rotator AxisRot, float Scale, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugCoordinateSystem" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( Vector* )params = AxisLoc;
				*( Rotator* )( params + 12 ) = AxisRot;
				*( float* )( params + 24 ) = Scale;
				*( bool* )( params + 28 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugSphere( Vector Center, float Radius, int Segments, byte R, byte G, byte B, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugSphere" );
				byte *params = ( byte* )( malloc( 27 ) );
				*( Vector* )params = Center;
				*( float* )( params + 12 ) = Radius;
				*( int* )( params + 16 ) = Segments;
				*( byte* )( params + 20 ) = R;
				*( byte* )( params + 21 ) = G;
				*( byte* )( params + 22 ) = B;
				*( bool* )( params + 24 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugCylinder( Vector Start, Vector End, float Radius, int Segments, byte R, byte G, byte B, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugCylinder" );
				byte *params = ( byte* )( malloc( 39 ) );
				*( Vector* )params = Start;
				*( Vector* )( params + 12 ) = End;
				*( float* )( params + 24 ) = Radius;
				*( int* )( params + 28 ) = Segments;
				*( byte* )( params + 32 ) = R;
				*( byte* )( params + 33 ) = G;
				*( byte* )( params + 34 ) = B;
				*( bool* )( params + 36 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugCone( Vector Origin, Vector Direction, float Length, float AngleWidth, float AngleHeight, int NumSides, void* DrawColor, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugCone" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )params = Origin;
				*( Vector* )( params + 12 ) = Direction;
				*( float* )( params + 24 ) = Length;
				*( float* )( params + 28 ) = AngleWidth;
				*( float* )( params + 32 ) = AngleHeight;
				*( int* )( params + 36 ) = NumSides;
				*( void** )( params + 40 ) = DrawColor;
				*( bool* )( params + 44 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugString( Vector TextLocation, ScriptArray< wchar_t > Text, class Actor* TestBaseActor, void* TextColor, float Duration )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugString" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )params = TextLocation;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Text;
				*( class Actor** )( params + 24 ) = TestBaseActor;
				*( void** )( params + 28 ) = TextColor;
				*( float* )( params + 32 ) = Duration;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugFrustrum( void* &FrustumToWorld, byte R, byte G, byte B, bool bPersistentLines )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DrawDebugFrustrum" );
				byte *params = ( byte* )( malloc( 71 ) );
				*( void** )params = FrustumToWorld;
				*( byte* )( params + 64 ) = R;
				*( byte* )( params + 65 ) = G;
				*( byte* )( params + 66 ) = B;
				*( bool* )( params + 68 ) = bPersistentLines;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FrustumToWorld = *( void** )params;
			}

			void FlushDebugStrings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FlushDebugStrings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChartData( ScriptArray< wchar_t > DataName, float DataValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ChartData" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = DataName;
				*( float* )( params + 12 ) = DataValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHidden( bool bNewHidden )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetHidden" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewHidden;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOnlyOwnerSee( bool bNewOnlyOwnerSee )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetOnlyOwnerSee" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewOnlyOwnerSee;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPhysics( byte newPhysics )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetPhysics" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = newPhysics;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Clock( float &Time )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Clock" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Time;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Time = *( float* )params;
			}

			void UnClock( float &Time )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.UnClock" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Time;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Time = *( float* )params;
			}

			void AttachComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.AttachComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DetachComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReattachComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ReattachComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTickGroup( byte NewTickGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetTickGroup" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = NewTickGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTickIsDisabled( bool bInDisabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetTickIsDisabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInDisabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GainedChild( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GainedChild" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LostChild( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.LostChild" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Timer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Timer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.HitWall" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Falling(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Falling" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Landed( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Landed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PhysicsVolumeChange( class PhysicsVolume* NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PhysicsVolumeChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicsVolume** )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostTouch( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PostTouch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnTouch( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.UnTouch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Bump( class Actor* Other, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Bump" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BaseChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.BaseChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Attach( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Attach" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Detach( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Detach" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* SpecialHandling( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SpecialHandling" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void CollisionChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CollisionChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool EncroachingOn( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.EncroachingOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EncroachedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.EncroachedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RanInto( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.RanInto" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnWakeRBPhysics(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnWakeRBPhysics" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSleepRBPhysics(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnSleepRBPhysics" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ClampRotation( Rotator &out_Rot, Rotator rBase, Rotator rUpperLimits, Rotator rLowerLimits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ClampRotation" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Rotator* )params = out_Rot;
				*( Rotator* )( params + 12 ) = rBase;
				*( Rotator* )( params + 24 ) = rUpperLimits;
				*( Rotator* )( params + 36 ) = rLowerLimits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Rot = *( Rotator* )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			bool OverRotated( Rotator &out_Desired, Rotator &out_Actual )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OverRotated" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )params = out_Desired;
				*( Rotator* )( params + 12 ) = out_Actual;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Desired = *( Rotator* )params;
				out_Actual = *( Rotator* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UsedBy( class Pawn* User )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.UsedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = User;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OutsideWorldBounds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OutsideWorldBounds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VolumeBasedDestroy( class PhysicsVolume* PV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.VolumeBasedDestroy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicsVolume** )params = PV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* Trace( Vector &HitLocation, Vector &HitNormal, Vector TraceEnd, Vector TraceStart, bool bTraceActors, Vector Extent, void* &HitInfo, int ExtraTraceFlags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Trace" );
				byte *params = ( byte* )( malloc( 96 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				*( Vector* )( params + 24 ) = TraceEnd;
				*( Vector* )( params + 36 ) = TraceStart;
				*( bool* )( params + 48 ) = bTraceActors;
				*( Vector* )( params + 52 ) = Extent;
				*( void** )( params + 64 ) = HitInfo;
				*( int* )( params + 92 ) = ExtraTraceFlags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				HitLocation = *( Vector* )params;
				HitNormal = *( Vector* )( params + 12 );
				HitInfo = *( void** )( params + 64 );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool TraceComponent( Vector &HitLocation, Vector &HitNormal, Vector TraceEnd, Vector TraceStart, Vector Extent, void* &HitInfo, bool bComplexCollision )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TraceComponent" );
				byte *params = ( byte* )( malloc( 96 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				*( Vector* )( params + 28 ) = TraceEnd;
				*( Vector* )( params + 40 ) = TraceStart;
				*( Vector* )( params + 52 ) = Extent;
				*( void** )( params + 64 ) = HitInfo;
				*( bool* )( params + 92 ) = bComplexCollision;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				HitLocation = *( Vector* )params;
				HitNormal = *( Vector* )( params + 12 );
				HitInfo = *( void** )( params + 64 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PointCheckComponent( Vector PointLocation, Vector PointExtent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PointCheckComponent" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )( params + 4 ) = PointLocation;
				*( Vector* )( params + 16 ) = PointExtent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FastTrace( Vector TraceEnd, Vector TraceStart, Vector BoxExtent, bool bTraceBullet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FastTrace" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( Vector* )params = TraceEnd;
				*( Vector* )( params + 12 ) = TraceStart;
				*( Vector* )( params + 24 ) = BoxExtent;
				*( bool* )( params + 36 ) = bTraceBullet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TraceAllPhysicsAssetInteractions( Vector EndTrace, Vector StartTrace, Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TraceAllPhysicsAssetInteractions" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( Vector* )( params + 4 ) = EndTrace;
				*( Vector* )( params + 16 ) = StartTrace;
				*( Vector* )( params + 40 ) = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindSpot( Vector BoxExtent, Vector &SpotLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FindSpot" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = BoxExtent;
				*( Vector* )( params + 12 ) = SpotLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				SpotLocation = *( Vector* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ContainsPoint( Vector Spot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ContainsPoint" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = Spot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsOverlapping( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsOverlapping" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetComponentsBoundingBox( void* &ActorBox )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetComponentsBoundingBox" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )params = ActorBox;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ActorBox = *( void** )params;
			}

			void GetBoundingCylinder( float &CollisionRadius, float &CollisionHeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetBoundingCylinder" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = CollisionRadius;
				*( float* )( params + 4 ) = CollisionHeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CollisionRadius = *( float* )params;
				CollisionHeight = *( float* )( params + 4 );
			}

			bool IsBlockedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsBlockedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Actor* Spawn( ScriptClass* SpawnClass, class Actor* SpawnOwner, ScriptName SpawnTag, Vector SpawnLocation, Rotator SpawnRotation, class Actor* ActorTemplate, bool bNoCollisionFail )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Spawn" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( ScriptClass** )params = SpawnClass;
				*( class Actor** )( params + 4 ) = SpawnOwner;
				*( ScriptName* )( params + 8 ) = SpawnTag;
				*( Vector* )( params + 16 ) = SpawnLocation;
				*( Rotator* )( params + 28 ) = SpawnRotation;
				*( class Actor** )( params + 40 ) = ActorTemplate;
				*( bool* )( params + 44 ) = bNoCollisionFail;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool Destroy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Destroy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TornOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TornOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTimer( float InRate, bool inbLoop, ScriptName inTimerFunc, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetTimer" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )params = InRate;
				*( bool* )( params + 4 ) = inbLoop;
				*( ScriptName* )( params + 8 ) = inTimerFunc;
				*( class Object** )( params + 16 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearTimer( ScriptName inTimerFunc, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ClearTimer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = inTimerFunc;
				*( class Object** )( params + 8 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearAllTimers( class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ClearAllTimers" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PauseTimer( bool bPause, ScriptName inTimerFunc, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PauseTimer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bPause;
				*( ScriptName* )( params + 4 ) = inTimerFunc;
				*( class Object** )( params + 12 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsTimerActive( ScriptName inTimerFunc, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsTimerActive" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = inTimerFunc;
				*( class Object** )( params + 8 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetTimerCount( ScriptName inTimerFunc, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetTimerCount" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = inTimerFunc;
				*( class Object** )( params + 8 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetTimerRate( ScriptName TimerFuncName, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetTimerRate" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = TimerFuncName;
				*( class Object** )( params + 8 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetRemainingTimeForTimer( ScriptName TimerFuncName, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetRemainingTimeForTimer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = TimerFuncName;
				*( class Object** )( params + 8 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void ModifyTimerTimeDilation( ScriptName TimerName, float InTimerTimeDilation, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ModifyTimerTimeDilation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = TimerName;
				*( float* )( params + 8 ) = InTimerTimeDilation;
				*( class Object** )( params + 12 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetTimerTimeDilation( ScriptName TimerName, class Object* inObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ResetTimerTimeDilation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = TimerName;
				*( class Object** )( params + 8 ) = inObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* CreateAudioComponent( class SoundCue* InSoundCue, bool bPlay, bool bStopWhenOwnerDestroyed, bool bUseLocation, Vector SourceLocation, bool bAttachToSelf )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CreateAudioComponent" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class SoundCue** )params = InSoundCue;
				*( bool* )( params + 4 ) = bPlay;
				*( bool* )( params + 8 ) = bStopWhenOwnerDestroyed;
				*( bool* )( params + 12 ) = bUseLocation;
				*( Vector* )( params + 16 ) = SourceLocation;
				*( bool* )( params + 28 ) = bAttachToSelf;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void PlaySound( class SoundCue* InSoundCue, bool bNotReplicated, bool bNoRepToOwner, bool bStopWhenOwnerDestroyed, Vector SoundLocation, bool bNoRepToRelevant )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PlaySound" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class SoundCue** )params = InSoundCue;
				*( bool* )( params + 4 ) = bNotReplicated;
				*( bool* )( params + 8 ) = bNoRepToOwner;
				*( bool* )( params + 12 ) = bStopWhenOwnerDestroyed;
				*( Vector* )( params + 16 ) = SoundLocation;
				*( bool* )( params + 28 ) = bNoRepToRelevant;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MakeNoise( float Loudness, ScriptName NoiseType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.MakeNoise" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = Loudness;
				*( ScriptName* )( params + 4 ) = NoiseType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PlayerCanSeeMe( bool bForceLOSCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PlayerCanSeeMe" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForceLOSCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SuggestTossVelocity( Vector &TossVelocity, Vector Destination, Vector Start, float TossSpeed, float BaseTossZ, float DesiredZPct, Vector CollisionSize, float TerminalVelocity, float OverrideGravityZ, bool bOnlyTraceUp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SuggestTossVelocity" );
				byte *params = ( byte* )( malloc( 72 ) );
				*( Vector* )params = TossVelocity;
				*( Vector* )( params + 12 ) = Destination;
				*( Vector* )( params + 24 ) = Start;
				*( float* )( params + 36 ) = TossSpeed;
				*( float* )( params + 40 ) = BaseTossZ;
				*( float* )( params + 44 ) = DesiredZPct;
				*( Vector* )( params + 48 ) = CollisionSize;
				*( float* )( params + 60 ) = TerminalVelocity;
				*( float* )( params + 64 ) = OverrideGravityZ;
				*( bool* )( params + 68 ) = bOnlyTraceUp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				TossVelocity = *( Vector* )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CalculateMinSpeedTrajectory( Vector &out_Velocity, Vector End, Vector Start, float MaxTossSpeed, float MinTossSpeed, Vector CollisionSize, float TerminalVelocity, float GravityZ, bool bOnlyTraceUp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CalculateMinSpeedTrajectory" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( Vector* )params = out_Velocity;
				*( Vector* )( params + 12 ) = End;
				*( Vector* )( params + 24 ) = Start;
				*( float* )( params + 36 ) = MaxTossSpeed;
				*( float* )( params + 40 ) = MinTossSpeed;
				*( Vector* )( params + 44 ) = CollisionSize;
				*( float* )( params + 56 ) = TerminalVelocity;
				*( float* )( params + 60 ) = GravityZ;
				*( bool* )( params + 64 ) = bOnlyTraceUp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Velocity = *( Vector* )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector GetDestination( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool PreTeleport( class Teleporter* InTeleporter )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PreTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Teleporter** )params = InTeleporter;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostTeleport( class Teleporter* OutTeleporter )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PostTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Teleporter** )params = OutTeleporter;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetURLMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetURLMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void AllActors( ScriptClass* BaseClass, class Actor* &Actor, ScriptClass* InterfaceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.AllActors" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				*( ScriptClass** )( params + 8 ) = InterfaceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
			}

			void DynamicActors( ScriptClass* BaseClass, class Actor* &Actor, ScriptClass* InterfaceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DynamicActors" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				*( ScriptClass** )( params + 8 ) = InterfaceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
			}

			void ChildActors( ScriptClass* BaseClass, class Actor* &Actor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ChildActors" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
			}

			void BasedActors( ScriptClass* BaseClass, class Actor* &Actor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.BasedActors" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
			}

			void TouchingActors( ScriptClass* BaseClass, class Actor* &Actor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TouchingActors" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
			}

			void TraceActors( ScriptClass* BaseClass, class Actor* &Actor, Vector &HitLoc, Vector &HitNorm, Vector End, Vector Start, Vector Extent, void* &HitInfo, int ExtraTraceFlags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TraceActors" );
				byte *params = ( byte* )( malloc( 100 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				*( Vector* )( params + 8 ) = HitLoc;
				*( Vector* )( params + 20 ) = HitNorm;
				*( Vector* )( params + 32 ) = End;
				*( Vector* )( params + 44 ) = Start;
				*( Vector* )( params + 56 ) = Extent;
				*( void** )( params + 68 ) = HitInfo;
				*( int* )( params + 96 ) = ExtraTraceFlags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
				HitLoc = *( Vector* )( params + 8 );
				HitNorm = *( Vector* )( params + 20 );
				HitInfo = *( void** )( params + 68 );
			}

			void VisibleActors( ScriptClass* BaseClass, class Actor* &Actor, float Radius, Vector Loc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.VisibleActors" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				*( float* )( params + 8 ) = Radius;
				*( Vector* )( params + 12 ) = Loc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
			}

			void VisibleCollidingActors( ScriptClass* BaseClass, class Actor* &Actor, float Radius, Vector Loc, bool bIgnoreHidden, Vector Extent, bool bTraceActors, ScriptClass* InterfaceClass, void* &HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.VisibleCollidingActors" );
				byte *params = ( byte* )( malloc( 76 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				*( float* )( params + 8 ) = Radius;
				*( Vector* )( params + 12 ) = Loc;
				*( bool* )( params + 24 ) = bIgnoreHidden;
				*( Vector* )( params + 28 ) = Extent;
				*( bool* )( params + 40 ) = bTraceActors;
				*( ScriptClass** )( params + 44 ) = InterfaceClass;
				*( void** )( params + 48 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
				HitInfo = *( void** )( params + 48 );
			}

			void CollidingActors( ScriptClass* BaseClass, class Actor* &Actor, float Radius, Vector Loc, bool bUseOverlapCheck, ScriptClass* InterfaceClass, void* &HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CollidingActors" );
				byte *params = ( byte* )( malloc( 60 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				*( float* )( params + 8 ) = Radius;
				*( Vector* )( params + 12 ) = Loc;
				*( bool* )( params + 24 ) = bUseOverlapCheck;
				*( ScriptClass** )( params + 28 ) = InterfaceClass;
				*( void** )( params + 32 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
				HitInfo = *( void** )( params + 32 );
			}

			void VisibleCollidingExtentActors( ScriptClass* BaseClass, class Actor* &Actor, float Radius, Vector Loc, Vector AltLoc, bool bIgnoreHidden, Vector Extent, bool bTraceActors, ScriptClass* InterfaceClass, void* &HitInfo, float XYCheckRadius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.VisibleCollidingExtentActors" );
				byte *params = ( byte* )( malloc( 92 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = Actor;
				*( float* )( params + 8 ) = Radius;
				*( Vector* )( params + 12 ) = Loc;
				*( Vector* )( params + 24 ) = AltLoc;
				*( bool* )( params + 36 ) = bIgnoreHidden;
				*( Vector* )( params + 40 ) = Extent;
				*( bool* )( params + 52 ) = bTraceActors;
				*( ScriptClass** )( params + 56 ) = InterfaceClass;
				*( void** )( params + 60 ) = HitInfo;
				*( float* )( params + 88 ) = XYCheckRadius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Actor = *( class Actor** )( params + 4 );
				HitInfo = *( void** )( params + 60 );
			}

			void OverlappingActors( ScriptClass* BaseClass, class Actor* &out_Actor, float Radius, Vector Loc, bool bIgnoreHidden )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OverlappingActors" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Actor** )( params + 4 ) = out_Actor;
				*( float* )( params + 8 ) = Radius;
				*( Vector* )( params + 12 ) = Loc;
				*( bool* )( params + 24 ) = bIgnoreHidden;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Actor = *( class Actor** )( params + 4 );
			}

			void ComponentList( ScriptClass* BaseClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ComponentList" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = BaseClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AllOwnedComponents( ScriptClass* BaseClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.AllOwnedComponents" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = BaseClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LocalPlayerControllers( ScriptClass* BaseClass, class PlayerController* &PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.LocalPlayerControllers" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = BaseClass;
				*( class PlayerController** )( params + 4 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PC = *( class PlayerController** )( params + 4 );
			}

			class PlayerController* GetALocalPlayerController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetALocalPlayerController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerController** )( params + function->return_val_offset() );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bGameRelevant, 0x10000 )
			ADD_VAR( ::BoolProperty, bStatic, 0x1 )
			ADD_OBJECT( WorldInfo, WorldInfo )
			ADD_VAR( ::BoolProperty, bNoDelete, 0x4 )
			void BroadcastLocalizedMessage( ScriptClass* InMessageClass, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.BroadcastLocalizedMessage" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptClass** )params = InMessageClass;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BroadcastLocalizedTeamMessage( int TeamIndex, ScriptClass* InMessageClass, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.BroadcastLocalizedTeamMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( int* )params = TeamIndex;
				*( ScriptClass** )( params + 4 ) = InMessageClass;
				*( int* )( params + 8 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 16 ) = RelatedPRI_;
				*( class Object** )( params + 20 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInitialState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetInitialState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bScriptInitialized, 0x800000 )
			ADD_VAR( ::NameProperty, InitialState, 0xFFFFFFFF )
			void ConstraintBrokenNotify( class Actor* ConOwner, class RB_ConstraintSetup* ConSetup, class RB_ConstraintInstance* ConInstance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ConstraintBrokenNotify" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Actor** )params = ConOwner;
				*( class RB_ConstraintSetup** )( params + 4 ) = ConSetup;
				*( class RB_ConstraintInstance** )( params + 8 ) = ConInstance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifySkelControlBeyondLimit( class SkelControlLookAt* LookAt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.NotifySkelControlBeyondLimit" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SkelControlLookAt** )params = LookAt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool StopsProjectile( class Projectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.StopsProjectile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bProjTarget, 0x80000000 )
			ADD_VAR( ::BoolProperty, bBlockActors, 0x40000000 )
			bool HurtRadius( float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.HurtRadius" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( float* )params = BaseDamage;
				*( float* )( params + 4 ) = DamageRadius;
				*( ScriptClass** )( params + 8 ) = DamageType;
				*( float* )( params + 12 ) = Momentum;
				*( Vector* )( params + 16 ) = HurtOrigin;
				*( class Actor** )( params + 28 ) = IgnoredActor;
				*( class Controller** )( params + 32 ) = InstigatedByController;
				*( bool* )( params + 36 ) = bDoFullDamage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Pawn, Instigator )
			ADD_VAR( ::BoolProperty, bHurtEntry, 0x8000 )
			ADD_VAR( ::BoolProperty, bWorldGeometry, 0x80 )
			ADD_VAR( ::BoolProperty, bCanBeDamaged, 0x80000 )
			void KilledBy( class Pawn* EventInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.KilledBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = EventInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )params = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HealDamage( int Amount, class Controller* Healer, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.HealDamage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = Amount;
				*( class Controller** )( params + 4 ) = Healer;
				*( ScriptClass** )( params + 8 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TakeRadiusDamage( class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TakeRadiusDamage" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Controller** )params = InstigatedBy;
				*( float* )( params + 4 ) = BaseDamage;
				*( float* )( params + 8 ) = DamageRadius;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( float* )( params + 16 ) = Momentum;
				*( Vector* )( params + 20 ) = HurtOrigin;
				*( bool* )( params + 32 ) = bFullDamage;
				*( class Actor** )( params + 36 ) = DamageCauser;
				*( float* )( params + 40 ) = DamageFalloffExponent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_STRUCT( ::VectorProperty, Location, 0xFFFFFFFF )
			void CheckHitInfo( void* &HitInfo, Vector Dir, Vector &out_HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CheckHitInfo" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )params = HitInfo;
				*( Vector* )( params + 32 ) = Dir;
				*( Vector* )( params + 44 ) = out_HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				HitInfo = *( void** )params;
				out_HitLocation = *( Vector* )( params + 44 );
			}

			ADD_STRUCT( ::RotatorProperty, Rotation, 0xFFFFFFFF )
			float GetGravityZ(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetGravityZ" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void DebugFreezeGame( class Actor* ActorToLookAt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DebugFreezeGame" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = ActorToLookAt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckForErrors(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CheckForErrors" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BecomeViewTarget( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.BecomeViewTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndViewTarget( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.EndViewTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CalcCamera( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CalcCamera" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )params = fDeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				*( float* )( params + 28 ) = out_FOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
				out_FOV = *( float* )( params + 28 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetItemName( ScriptArray< wchar_t > FullName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetItemName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = FullName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetHumanReadableName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetHumanReadableName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ReplaceText( ScriptArray< wchar_t > &Text, ScriptArray< wchar_t > Replace, ScriptArray< wchar_t > With )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ReplaceText" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )params = Text;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Replace;
				*( ScriptArray< wchar_t >* )( params + 24 ) = With;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Text = *( ScriptArray< wchar_t >* )params;
			}

			ScriptArray< wchar_t > GetLocalString( int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetLocalString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = Switch;
				*( class PlayerReplicationInfo** )( params + 4 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI_;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void MatchStarting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.MatchStarting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetDebugName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetDebugName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			ADD_VAR( ::BoolProperty, bDeleteMe, 0x8 )
			ADD_VAR( ::ByteProperty, Role, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RemoteRole, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bTearOff, 0x4000000 )
			ADD_OBJECT( PhysicsVolume, PhysicsVolume )
			ADD_OBJECT( Actor, Base )
			ADD_VAR( ::BoolProperty, bBounce, 0x200 )
			ADD_VAR( ::BoolProperty, bHardAttach, 0x400 )
			ADD_STRUCT( ::VectorProperty, RelativeLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, RelativeRotation, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BaseBoneName, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Velocity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Acceleration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCollideActors, 0x8000000 )
			ADD_VAR( ::BoolProperty, bCollideWorld, 0x10000000 )
			ADD_OBJECT( Actor, Owner )
			ScriptArray< wchar_t > GetPhysicsName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetPhysicsName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, Physics, 0xFFFFFFFF )
			void ModifyHearSoundComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ModifyHearSoundComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetFaceFXAudioComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetFaceFXAudioComponent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsInPain(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsInPain" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayTeleportEffect( bool bOut, bool bSound )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PlayTeleportEffect" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bOut;
				*( bool* )( params + 4 ) = bSound;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanSplash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CanSplash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ApplyFluidSurfaceImpact( class FluidSurfaceActor* Fluid, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ApplyFluidSurfaceImpact" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class FluidSurfaceActor** )params = Fluid;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bAllowFluidSurfaceInteraction, 0x10000000 )
			bool EffectIsRelevant( Vector SpawnLocation, bool bForceDedicated, float VisibleCullDistance, float HiddenCullDistance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.EffectIsRelevant" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = SpawnLocation;
				*( bool* )( params + 12 ) = bForceDedicated;
				*( float* )( params + 16 ) = VisibleCullDistance;
				*( float* )( params + 20 ) = HiddenCullDistance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bDebugEffectIsRelevant, 0x8000000 )
			void DebugMessagePlayer( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DebugMessagePlayer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastRenderTime, 0xFFFFFFFF )
			bool TriggerEventClass( ScriptClass* InEventClass, class Actor* InInstigator, int ActivateIndex, bool bTest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TriggerEventClass" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptClass** )params = InEventClass;
				*( class Actor** )( params + 4 ) = InInstigator;
				*( int* )( params + 8 ) = ActivateIndex;
				*( bool* )( params + 12 ) = bTest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ActivateEventClass( ScriptClass* InClass, class Actor* InInstigator, bool bTest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ActivateEventClass" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( ScriptClass** )params = InClass;
				*( class Actor** )( params + 4 ) = InInstigator;
				*( bool* )( params + 32 ) = bTest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ReceivedNewEvent( class SequenceEvent* Evt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ReceivedNewEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SequenceEvent** )params = Evt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TriggerGlobalEventClass( ScriptClass* InEventClass, class Actor* InInstigator, int ActivateIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TriggerGlobalEventClass" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptClass** )params = InEventClass;
				*( class Actor** )( params + 4 ) = InInstigator;
				*( int* )( params + 8 ) = ActivateIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindEventsOfClass( ScriptClass* EventClass, bool bIncludeDisabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FindEventsOfClass" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptClass** )params = EventClass;
				*( bool* )( params + 16 ) = bIncludeDisabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearLatentAction( ScriptClass* actionClass, bool bAborted, class SeqAct_Latent* exceptionAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ClearLatentAction" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptClass** )params = actionClass;
				*( bool* )( params + 4 ) = bAborted;
				*( class SeqAct_Latent** )( params + 8 ) = exceptionAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDestroy( class SeqAct_Destroy* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnDestroy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Destroy** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceNetRelevant(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ForceNetRelevant" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bAlwaysRelevant, 0x200000 )
			ADD_VAR( ::FloatProperty, NetUpdateFrequency, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceNetUpdate, 0x100 )
			void SetNetUpdateTime( float NewUpdateTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetNetUpdateTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewUpdateTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ShutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bHidden, 0x2 )
			void PrestreamTextures( float Seconds, bool bEnableStreaming, int CinematicTextureGroups )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PrestreamTextures" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = Seconds;
				*( bool* )( params + 4 ) = bEnableStreaming;
				*( int* )( params + 8 ) = CinematicTextureGroups;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnModifyHealth( class SeqAct_ModifyHealth* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnModifyHealth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ModifyHealth** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTeleport( class SeqAct_Teleport* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Teleport** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bUpdateSimulatedPosition, 0x2000000 )
			ADD_VAR( ::BoolProperty, bNetDirty, 0x100000 )
			void OnSetVelocity( class SeqAct_SetVelocity* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnSetVelocity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetVelocity** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetBlockRigidBody( class SeqAct_SetBlockRigidBody* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnSetBlockRigidBody" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetBlockRigidBody** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetPhysics( class SeqAct_SetPhysics* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnSetPhysics" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetPhysics** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bOnlyDirtyReplication, 0x8000000 )
			void OnChangeCollision( class SeqAct_ChangeCollision* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnChangeCollision" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ChangeCollision** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggleHidden( class SeqAct_ToggleHidden* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnToggleHidden" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ToggleHidden** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAttachToActor( class SeqAct_AttachToActor* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnAttachToActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_AttachToActor** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoKismetAttachment( class Actor* Attachment, class SeqAct_AttachToActor* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.DoKismetAttachment" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = Attachment;
				*( class SeqAct_AttachToActor** )( params + 4 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAnimEnd( class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnAnimEnd" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class AnimNodeSequence** )params = SeqNode;
				*( float* )( params + 4 ) = PlayedTime;
				*( float* )( params + 8 ) = ExcessTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAnimPlay( class AnimNodeSequence* SeqNode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnAnimPlay" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNodeSequence** )params = SeqNode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.BeginAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )params = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAnimPosition( ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetAnimPosition" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )params = SlotName;
				*( int* )( params + 8 ) = ChannelIndex;
				*( ScriptName* )( params + 12 ) = InAnimSeqName;
				*( float* )( params + 20 ) = InPosition;
				*( bool* )( params + 24 ) = bFireNotifies;
				*( bool* )( params + 28 ) = bLooping;
				*( bool* )( params + 32 ) = bEnableRootMotion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FinishAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )params = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PlayActorFaceFXAnim( class FaceFXAnimSet* AnimSet, ScriptArray< wchar_t > GroupName, ScriptArray< wchar_t > SeqName, class SoundCue* SoundCueToPlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PlayActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class FaceFXAnimSet** )params = AnimSet;
				*( ScriptArray< wchar_t >* )( params + 4 ) = GroupName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = SeqName;
				*( class SoundCue** )( params + 28 ) = SoundCueToPlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StopActorFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.StopActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMorphWeight( ScriptName MorphNodeName, float MorphWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetMorphWeight" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = MorphNodeName;
				*( float* )( params + 8 ) = MorphWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkelControlScale( ScriptName SkelControlName, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetSkelControlScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SkelControlName;
				*( float* )( params + 8 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsActorPlayingFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsActorPlayingFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanActorPlayFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CanActorPlayFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class FaceFXAsset* GetActorFaceFXAsset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetActorFaceFXAsset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class FaceFXAsset** )( params + function->return_val_offset() );
			}

			bool IsStationary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsStationary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetActorEyesViewPoint( Vector &out_Location, Rotator &out_Rotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetActorEyesViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = out_Location;
				*( Rotator* )( params + 12 ) = out_Rotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Location = *( Vector* )params;
				out_Rotation = *( Rotator* )( params + 12 );
			}

			bool IsPlayerOwned(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsPlayerOwned" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PawnBaseDied(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PawnBaseDied" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte ScriptGetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ScriptGetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void NotifyLocalPlayerTeamReceived(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.NotifyLocalPlayerTeamReceived" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindGoodEndView( class PlayerController* PC, Rotator &GoodRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.FindGoodEndView" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )params = PC;
				*( Rotator* )( params + 4 ) = GoodRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				GoodRotation = *( Rotator* )( params + 4 );
			}

			Vector GetTargetLocation( class Actor* RequestedBy, bool bRequestAlternateLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetTargetLocation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = RequestedBy;
				*( bool* )( params + 4 ) = bRequestAlternateLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void SpawnedByKismet(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SpawnedByKismet" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationStarted( class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.InterpolationStarted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SeqAct_Interp** )params = InterpAction;
				*( class InterpGroupInst** )( params + 4 ) = GroupInst;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationFinished( class SeqAct_Interp* InterpAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.InterpolationFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Interp** )params = InterpAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationChanged( class SeqAct_Interp* InterpAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.InterpolationChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Interp** )params = InterpAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RigidBodyCollision( void* &RigidCollisionData, int ContactIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.RigidBodyCollision" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 8 ) = RigidCollisionData;
				*( int* )( params + 44 ) = ContactIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				RigidCollisionData = *( void** )( params + 8 );
			}

			void OnRanOver( class SVehicle* Vehicle, int WheelIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnRanOver" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SVehicle** )params = Vehicle;
				*( int* )( params + 8 ) = WheelIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHUDLocation( Vector NewHUDLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SetHUDLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewHUDLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NativePostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.NativePostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RootMotionModeChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.RootMotionModeChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RootMotionExtracted( void* &ExtractedRootMotionDelta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.RootMotionExtracted" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 16 ) = ExtractedRootMotionDelta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ExtractedRootMotionDelta = *( void** )( params + 16 );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetPackageGuid( ScriptName PackageName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetPackageGuid" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = PackageName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void OnRigidBodySpringOverextension( class RB_BodyInstance* BodyInstance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.OnRigidBodySpringOverextension" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class RB_BodyInstance** )params = BodyInstance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsInPersistentLevel( bool bIncludeLevelStreamingPersistent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.IsInPersistentLevel" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIncludeLevelStreamingPersistent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetAimFrictionExtent( float &Width, float &Height, Vector &Center )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetAimFrictionExtent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )params = Width;
				*( float* )( params + 4 ) = Height;
				*( Vector* )( params + 8 ) = Center;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Width = *( float* )params;
				Height = *( float* )( params + 4 );
				Center = *( Vector* )( params + 8 );
			}

			ADD_VAR( ::BoolProperty, bCanBeFrictionedTo, 0x4000 )
			void GetAimAdhesionExtent( float &Width, float &Height, Vector &Center )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetAimAdhesionExtent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )params = Width;
				*( float* )( params + 4 ) = Height;
				*( Vector* )( params + 8 ) = Center;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Width = *( float* )params;
				Height = *( float* )( params + 4 );
				Center = *( Vector* )( params + 8 );
			}

			ADD_VAR( ::BoolProperty, bCanBeAdheredTo, 0x2000 )
			bool PlayParticleEffect( class AnimNotify_PlayParticleEffect* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PlayParticleEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_PlayParticleEffect** )params = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CreateForceField( class AnimNotify_ForceField* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.CreateForceField" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_ForceField** )params = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TrailsNotify( class AnimNotify_Trails* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TrailsNotify" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_Trails** )params = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TrailsNotifyTick( class AnimNotify_Trails* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TrailsNotifyTick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_Trails** )params = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TrailsNotifyEnd( class AnimNotify_Trails* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.TrailsNotifyEnd" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_Trails** )params = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SupportsKismetModification( class SequenceOp* AskingOp, ScriptArray< wchar_t > &Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.SupportsKismetModification" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class SequenceOp** )params = AskingOp;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Reason = *( ScriptArray< wchar_t >* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AnimTreeUpdated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.AnimTreeUpdated" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostDemoRewind(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.PostDemoRewind" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicationEnded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ReplicationEnded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetAvoidanceVector( Vector GoalLocation, float CollisionRadius, float MaxSpeed, int NumSamples, float VelocityStepRate, float MaxTimeTilOverlap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetAvoidanceVector" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( Vector* )( params + 12 ) = GoalLocation;
				*( float* )( params + 24 ) = CollisionRadius;
				*( float* )( params + 28 ) = MaxSpeed;
				*( int* )( params + 32 ) = NumSamples;
				*( float* )( params + 36 ) = VelocityStepRate;
				*( float* )( params + 40 ) = MaxTimeTilOverlap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool WillOverlap( Vector PosA, Vector VelA, Vector PosB, Vector VelB, float StepSize, float Radius, float &Time )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.WillOverlap" );
				byte *params = ( byte* )( malloc( 60 ) );
				*( Vector* )params = PosA;
				*( Vector* )( params + 12 ) = VelA;
				*( Vector* )( params + 24 ) = PosB;
				*( Vector* )( params + 36 ) = VelB;
				*( float* )( params + 48 ) = StepSize;
				*( float* )( params + 52 ) = Radius;
				*( float* )( params + 56 ) = Time;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Time = *( float* )( params + 56 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldBeHiddenBySHOW_NavigationNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.ShouldBeHiddenBySHOW_NavigationNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetSpectatorName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetSpectatorName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetSpectatorDescription(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetSpectatorDescription" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void GetSpectatorHealthInfo( int &Health, int &MaxHealth )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Actor.GetSpectatorHealthInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Health;
				*( int* )( params + 4 ) = MaxHealth;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Health = *( int* )params;
				MaxHealth = *( int* )( params + 4 );
			}

			ADD_VAR( ::BoolProperty, bSkipActorPropertyReplication, 0x1000000 )
			ADD_VAR( ::BoolProperty, bNetInitial, 0x800 )
			ADD_VAR( ::BoolProperty, bReplicateMovement, 0x800000 )
			ADD_VAR( ::BoolProperty, bReplicateInstigator, 0x400000 )
			ADD_VAR( ::BoolProperty, bNetOwner, 0x1000 )
			ADD_VAR( ::FloatProperty, DrawScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DrawScale3D, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PrePivot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CustomTimeDilation, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CollisionType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ReplicatedCollisionType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, TickGroup, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bTicked, 0x10 )
			ADD_VAR( ::BoolProperty, bOnlyOwnerSee, 0x20 )
			ADD_VAR( ::BoolProperty, bTickIsDisabled, 0x40 )
			ADD_VAR( ::BoolProperty, bIgnoreRigidBodyPawns, 0x100 )
			ADD_VAR( ::BoolProperty, bOrientOnSlope, 0x200 )
			ADD_VAR( ::BoolProperty, bIgnoreEncroachers, 0x400 )
			ADD_VAR( ::BoolProperty, bPushedByEncroachers, 0x800 )
			ADD_VAR( ::BoolProperty, bDestroyedByInterpActor, 0x1000 )
			ADD_VAR( ::BoolProperty, bRouteBeginPlayEvenIfStatic, 0x2000 )
			ADD_VAR( ::BoolProperty, bIsMoving, 0x4000 )
			ADD_VAR( ::BoolProperty, bAlwaysEncroachCheck, 0x8000 )
			ADD_VAR( ::BoolProperty, bHasAlternateTargetLocation, 0x10000 )
			ADD_VAR( ::BoolProperty, bCanStepUpOn, 0x20000 )
			ADD_VAR( ::BoolProperty, bNetTemporary, 0x40000 )
			ADD_VAR( ::BoolProperty, bOnlyRelevantToOwner, 0x80000 )
			ADD_VAR( ::BoolProperty, bDemoRecording, 0x20000000 )
			ADD_VAR( ::BoolProperty, bDemoOwner, 0x40000000 )
			ADD_VAR( ::BoolProperty, bForceDemoRelevant, 0x80000000 )
			ADD_VAR( ::BoolProperty, bNetInitialRotation, 0x1 )
			ADD_VAR( ::BoolProperty, bReplicateRigidBodyLocation, 0x2 )
			ADD_VAR( ::BoolProperty, bKillDuringLevelTransition, 0x4 )
			ADD_VAR( ::BoolProperty, bExchangedRoles, 0x8 )
			ADD_VAR( ::BoolProperty, bConsiderAllStaticMeshComponentsForStreaming, 0x10 )
			ADD_VAR( ::BoolProperty, bDebug, 0x20 )
			ADD_VAR( ::BoolProperty, bPostRenderIfNotVisible, 0x40 )
			ADD_VAR( ::BoolProperty, s_bThrottleNetRelevancy, 0x80 )
			ADD_VAR( ::BoolProperty, bPendingNetUpdate, 0x200 )
			ADD_VAR( ::BoolProperty, bIgnoreBaseRotation, 0x800 )
			ADD_VAR( ::BoolProperty, bShadowParented, 0x1000 )
			ADD_VAR( ::BoolProperty, bMovable, 0x20000 )
			ADD_VAR( ::BoolProperty, bDestroyInPainVolume, 0x40000 )
			ADD_VAR( ::BoolProperty, bShouldBaseAtStartup, 0x100000 )
			ADD_VAR( ::BoolProperty, bPendingDelete, 0x200000 )
			ADD_VAR( ::BoolProperty, bCanTeleport, 0x400000 )
			ADD_VAR( ::BoolProperty, bAlwaysTick, 0x800000 )
			ADD_VAR( ::BoolProperty, bBlocksNavigation, 0x1000000 )
			ADD_VAR( ::BoolProperty, BlockRigidBody, 0x2000000 )
			ADD_VAR( ::BoolProperty, bCollideWhenPlacing, 0x4000000 )
			ADD_VAR( ::BoolProperty, bCollideComplex, 0x20000000 )
			ADD_VAR( ::BoolProperty, bBlocksTeleport, 0x1 )
			ADD_VAR( ::BoolProperty, bMoveIgnoresDestruction, 0x2 )
			ADD_VAR( ::BoolProperty, bNoEncroachCheck, 0x4 )
			ADD_VAR( ::BoolProperty, bCollideAsEncroacher, 0x8 )
			ADD_VAR( ::BoolProperty, bPhysRigidBodyOutOfWorldCheck, 0x10 )
			ADD_VAR( ::BoolProperty, bComponentOutsideWorld, 0x20 )
			ADD_VAR( ::BoolProperty, bForceOctreeSNFilter, 0x40 )
			ADD_VAR( ::BoolProperty, bRigidBodyWasAwake, 0x80 )
			ADD_VAR( ::BoolProperty, bCallRigidBodyWakeEvents, 0x100 )
			ADD_VAR( ::BoolProperty, bJustTeleported, 0x400 )
			ADD_VAR( ::BoolProperty, bHiddenEd, 0x2000 )
			ADD_VAR( ::BoolProperty, bEditable, 0x4000 )
			ADD_VAR( ::BoolProperty, bHiddenEdGroup, 0x8000 )
			ADD_VAR( ::BoolProperty, bHiddenEdCustom, 0x10000 )
			ADD_VAR( ::BoolProperty, bHiddenEdTemporary, 0x20000 )
			ADD_VAR( ::BoolProperty, bHiddenEdLevel, 0x40000 )
			ADD_VAR( ::BoolProperty, bEdShouldSnap, 0x80000 )
			ADD_VAR( ::BoolProperty, bTempEditor, 0x100000 )
			ADD_VAR( ::BoolProperty, bPathColliding, 0x200000 )
			ADD_VAR( ::BoolProperty, bPathTemp, 0x400000 )
			ADD_VAR( ::BoolProperty, bLockLocation, 0x1000000 )
			ADD_VAR( ::BoolProperty, bForceAllowKismetModification, 0x2000000 )
			ADD_VAR( ::BoolProperty, m_bPotentialSeekingTarget, 0x4000000 )
			ADD_VAR( ::IntProperty, NetTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IndexInTickList, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastSlowRelevancyCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NetUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NetPriority, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastNetUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeSinceLastTick, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TickFrequency, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TickFrequencyAtEndDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TickFrequencyDecreaseDistanceStart, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TickFrequencyDecreaseDistanceEnd, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TickFrequencyLastSeenTimeBeforeForcingMaxTickFrequency, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LifeSpan, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CreationTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, Tag, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, Group, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LatentFloat, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeSequence, LatentSeqNode )
			ADD_STRUCT( ::VectorProperty, AngularVelocity, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OverlapTag, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, RotationRate, 0xFFFFFFFF )
			ADD_OBJECT( Actor, PendingTouch )
			ADD_OBJECT( ScriptClass, MessageClass )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
