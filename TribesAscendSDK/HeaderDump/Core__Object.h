#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Core.Object." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Core.Object." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Core.Object." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Object
	{
	public:
			int GetBuildChangelistNumber(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetBuildChangelistNumber" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetEngineVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetEngineVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void GetSystemTime( int &Year, int &Month, int &DayOfWeek, int &Day, int &Hour, int &Min, int &Sec, int &MSec )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetSystemTime" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( int* )( params + 0 ) = Year;
				*( int* )( params + 4 ) = Month;
				*( int* )( params + 8 ) = DayOfWeek;
				*( int* )( params + 12 ) = Day;
				*( int* )( params + 16 ) = Hour;
				*( int* )( params + 20 ) = Min;
				*( int* )( params + 24 ) = Sec;
				*( int* )( params + 28 ) = MSec;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Year = *( int* )( params + 0 );
				Month = *( int* )( params + 4 );
				DayOfWeek = *( int* )( params + 8 );
				Day = *( int* )( params + 12 );
				Hour = *( int* )( params + 16 );
				Min = *( int* )( params + 20 );
				Sec = *( int* )( params + 24 );
				MSec = *( int* )( params + 28 );
			}

			ScriptArray< wchar_t > TimeStamp(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.TimeStamp" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			Vector TransformVectorByRotation( Rotator SourceRotation, Vector SourceVector, bool bInverse )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.TransformVectorByRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Rotator* )( params + 0 ) = SourceRotation;
				*( Vector* )( params + 12 ) = SourceVector;
				*( bool* )( params + 24 ) = bInverse;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ScriptName GetPackageName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetPackageName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool IsPendingKill(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.IsPendingKill" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Object, Outer )
			ADD_VAR( ::NameProperty, Name, 0xFFFFFFFF )
			float ByteToFloat( byte inputByte, bool bSigned )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ByteToFloat" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = inputByte;
				*( bool* )( params + 4 ) = bSigned;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			byte FloatToByte( float inputFloat, bool bSigned )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FloatToByte" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = inputFloat;
				*( bool* )( params + 4 ) = bSigned;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			float UnwindHeading( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.UnwindHeading" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FindDeltaAngle( float A1, float A2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FindDeltaAngle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A1;
				*( float* )( params + 4 ) = A2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetHeadingAngle( Vector Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetHeadingAngle" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void GetAngularDegreesFromRadians( void* &OutFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetAngularDegreesFromRadians" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = OutFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutFOV = *( void** )( params + 0 );
			}

			float Acos( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Acos" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void GetAngularFromDotDist( void* &OutAngDist, void* DotDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetAngularFromDotDist" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = OutAngDist;
				*( void** )( params + 8 ) = DotDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutAngDist = *( void** )( params + 0 );
			}

			bool GetAngularDistance( void* &OutAngularDist, Vector Direction, Vector AxisX, Vector AxisY, Vector AxisZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetAngularDistance" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )( params + 0 ) = OutAngularDist;
				*( Vector* )( params + 8 ) = Direction;
				*( Vector* )( params + 20 ) = AxisX;
				*( Vector* )( params + 32 ) = AxisY;
				*( Vector* )( params + 44 ) = AxisZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutAngularDist = *( void** )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetDotDistance( void* &OutDotDist, Vector Direction, Vector AxisX, Vector AxisY, Vector AxisZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetDotDistance" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )( params + 0 ) = OutDotDist;
				*( Vector* )( params + 8 ) = Direction;
				*( Vector* )( params + 20 ) = AxisX;
				*( Vector* )( params + 32 ) = AxisY;
				*( Vector* )( params + 44 ) = AxisZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutDotDist = *( void** )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector PointProjectToPlane( Vector Point, Vector A, Vector B, Vector C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PointProjectToPlane" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )( params + 0 ) = Point;
				*( Vector* )( params + 12 ) = A;
				*( Vector* )( params + 24 ) = B;
				*( Vector* )( params + 36 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float PointDistToPlane( Vector Point, Rotator Orientation, Vector Origin, Vector &out_ClosestPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PointDistToPlane" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )( params + 0 ) = Point;
				*( Rotator* )( params + 12 ) = Orientation;
				*( Vector* )( params + 24 ) = Origin;
				*( Vector* )( params + 36 ) = out_ClosestPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ClosestPoint = *( Vector* )( params + 36 );
				return *( float* )( params + function->return_val_offset() );
			}

			float PointDistToSegment( Vector Point, Vector StartPoint, Vector EndPoint, Vector &OutClosestPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PointDistToSegment" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )( params + 0 ) = Point;
				*( Vector* )( params + 12 ) = StartPoint;
				*( Vector* )( params + 24 ) = EndPoint;
				*( Vector* )( params + 36 ) = OutClosestPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutClosestPoint = *( Vector* )( params + 36 );
				return *( float* )( params + function->return_val_offset() );
			}

			float PointDistToLine( Vector Point, Vector Line, Vector Origin, Vector &OutClosestPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PointDistToLine" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )( params + 0 ) = Point;
				*( Vector* )( params + 12 ) = Line;
				*( Vector* )( params + 24 ) = Origin;
				*( Vector* )( params + 36 ) = OutClosestPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutClosestPoint = *( Vector* )( params + 36 );
				return *( float* )( params + function->return_val_offset() );
			}

			bool GetPerObjectConfigSections( ScriptClass* SearchClass, class Object* ObjectOuter, int MaxResults )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetPerObjectConfigSections" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptClass** )( params + 0 ) = SearchClass;
				*( class Object** )( params + 16 ) = ObjectOuter;
				*( int* )( params + 20 ) = MaxResults;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StaticSaveConfig(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.StaticSaveConfig" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveConfig(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SaveConfig" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Object* FindObject( ScriptArray< wchar_t > ObjectName, ScriptClass* ObjectClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FindObject" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = ObjectName;
				*( ScriptClass** )( params + 12 ) = ObjectClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Object** )( params + function->return_val_offset() );
			}

			class Object* DynamicLoadObject( ScriptArray< wchar_t > ObjectName, ScriptClass* ObjectClass, bool MayFail )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DynamicLoadObject" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = ObjectName;
				*( ScriptClass** )( params + 12 ) = ObjectClass;
				*( bool* )( params + 16 ) = MayFail;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Object** )( params + function->return_val_offset() );
			}

			ScriptName GetEnum( class Object* E, int I )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetEnum" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Object** )( params + 0 ) = E;
				*( int* )( params + 4 ) = I;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void Disable( ScriptName ProbeFunc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Disable" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ProbeFunc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Enable( ScriptName ProbeFunc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Enable" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ProbeFunc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ContinuedState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ContinuedState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PausedState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PausedState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PoppedState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PoppedState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PushedState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PushedState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndState( ScriptName NextStateName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EndState" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = NextStateName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginState( ScriptName PreviousStateName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.BeginState" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = PreviousStateName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DumpStateStack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DumpStateStack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopState( bool bPopAll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PopState" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bPopAll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PushState( ScriptName NewState, ScriptName NewLabel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PushState" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = NewState;
				*( ScriptName* )( params + 8 ) = NewLabel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptName GetStateName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetStateName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool IsChildState( ScriptName TestState, ScriptName TestParentState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.IsChildState" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = TestState;
				*( ScriptName* )( params + 8 ) = TestParentState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsInState( ScriptName TestState, bool bTestStateStack )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.IsInState" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = TestState;
				*( bool* )( params + 8 ) = bTestStateStack;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GotoState( ScriptName NewState, ScriptName Label, bool bForceEvents, bool bKeepStack )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GotoState" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = NewState;
				*( ScriptName* )( params + 8 ) = Label;
				*( bool* )( params + 16 ) = bForceEvents;
				*( bool* )( params + 20 ) = bKeepStack;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsUTracing(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.IsUTracing" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetUTracing( bool bShouldUTrace )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SetUTracing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bShouldUTrace;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptName GetFuncName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetFuncName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void DebugBreak( int UserFlags, byte DebuggerType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DebugBreak" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( int* )( params + 0 ) = UserFlags;
				*( byte* )( params + 4 ) = DebuggerType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetScriptTrace(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetScriptTrace" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ScriptTrace(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ScriptTrace" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > ParseLocalizedPropertyPath( ScriptArray< wchar_t > PathName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ParseLocalizedPropertyPath" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PathName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Localize( ScriptArray< wchar_t > SectionName, ScriptArray< wchar_t > KeyName, ScriptArray< wchar_t > PackageName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Localize" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = SectionName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = KeyName;
				*( ScriptArray< wchar_t >* )( params + 24 ) = PackageName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ParseStringIntoArray( ScriptArray< wchar_t > BaseString, ScriptArray< wchar_t > delim, bool bCullEmpty )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ParseStringIntoArray" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = BaseString;
				*( ScriptArray< wchar_t >* )( params + 24 ) = delim;
				*( bool* )( params + 36 ) = bCullEmpty;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WarnInternal( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.WarnInternal" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogInternal( ScriptArray< wchar_t > S, ScriptName Tag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.LogInternal" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				*( ScriptName* )( params + 12 ) = Tag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* Subtract_LinearColorLinearColor( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_LinearColorLinearColor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 16 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Multiply_LinearColorFloat( void* LC, float Mult )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_LinearColorFloat" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = LC;
				*( float* )( params + 16 ) = Mult;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* ColorToLinearColor( void* OldColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ColorToLinearColor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = OldColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* MakeLinearColor( float R, float G, float B, float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MakeLinearColor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = R;
				*( float* )( params + 4 ) = G;
				*( float* )( params + 8 ) = B;
				*( float* )( params + 12 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* LerpColor( void* A, void* B, float Alpha )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.LerpColor" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 4 ) = B;
				*( float* )( params + 8 ) = Alpha;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* MakeColor( byte R, byte G, byte B, byte A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MakeColor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( byte* )( params + 0 ) = R;
				*( byte* )( params + 1 ) = G;
				*( byte* )( params + 2 ) = B;
				*( byte* )( params + 3 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Add_ColorColor( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Add_ColorColor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Multiply_ColorFloat( void* A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_ColorFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Multiply_FloatColor( float A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_FloatColor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( void** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Subtract_ColorColor( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_ColorColor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* EvalInterpCurveVector2D( void* Vector2DCurve, float InVal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EvalInterpCurveVector2D" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = Vector2DCurve;
				*( float* )( params + 16 ) = InVal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			Vector EvalInterpCurveVector( void* VectorCurve, float InVal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EvalInterpCurveVector" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = VectorCurve;
				*( float* )( params + 16 ) = InVal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float EvalInterpCurveFloat( void* FloatCurve, float InVal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EvalInterpCurveFloat" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = FloatCurve;
				*( float* )( params + 16 ) = InVal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void* vect2d( float InX, float InY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.vect2d" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = InX;
				*( float* )( params + 4 ) = InY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			float GetMappedRangeValue( void* InputRange, void* OutputRange, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetMappedRangeValue" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = InputRange;
				*( void** )( params + 8 ) = OutputRange;
				*( float* )( params + 16 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetRangePctByValue( void* Range, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetRangePctByValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = Range;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetRangeValueByPct( void* Range, float Pct )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetRangeValueByPct" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = Range;
				*( float* )( params + 8 ) = Pct;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void* SubtractEqual_Vector2DVector2D( void* &A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractEqual_Vector2DVector2D" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( void** )( params + 0 );
				return *( void** )( params + function->return_val_offset() );
			}

			void* AddEqual_Vector2DVector2D( void* &A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddEqual_Vector2DVector2D" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( void** )( params + 0 );
				return *( void** )( params + function->return_val_offset() );
			}

			void* DivideEqual_Vector2DFloat( void* &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DivideEqual_Vector2DFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = A;
				*( float* )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( void** )( params + 0 );
				return *( void** )( params + function->return_val_offset() );
			}

			void* MultiplyEqual_Vector2DFloat( void* &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyEqual_Vector2DFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = A;
				*( float* )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( void** )( params + 0 );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Divide_Vector2DFloat( void* A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Divide_Vector2DFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = A;
				*( float* )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Multiply_Vector2DFloat( void* A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_Vector2DFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = A;
				*( float* )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Subtract_Vector2DVector2D( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_Vector2DVector2D" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Add_Vector2DVector2D( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Add_Vector2DVector2D" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Subtract_QuatQuat( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_QuatQuat" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 16 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* Add_QuatQuat( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Add_QuatQuat" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 16 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* QuatSlerp( void* A, void* B, float Alpha, bool bShortestPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatSlerp" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 16 ) = B;
				*( float* )( params + 32 ) = Alpha;
				*( bool* )( params + 36 ) = bShortestPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			Rotator QuatToRotator( void* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatToRotator" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void* QuatFromRotator( Rotator A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatFromRotator" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* QuatFromAxisAndAngle( Vector Axis, float Angle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatFromAxisAndAngle" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = Axis;
				*( float* )( params + 12 ) = Angle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* QuatFindBetween( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatFindBetween" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			Vector QuatRotateVector( void* A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatRotateVector" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )( params + 0 ) = A;
				*( Vector* )( params + 16 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void* QuatInvert( void* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatInvert" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			float QuatDot( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatDot" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 16 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void* QuatProduct( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.QuatProduct" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 16 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			Vector MatrixGetAxis( void* TM, byte Axis )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MatrixGetAxis" );
				byte *params = ( byte* )( malloc( 65 ) );
				*( void** )( params + 0 ) = TM;
				*( byte* )( params + 64 ) = Axis;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector MatrixGetOrigin( void* TM )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MatrixGetOrigin" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( void** )( params + 0 ) = TM;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Rotator MatrixGetRotator( void* TM )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MatrixGetRotator" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( void** )( params + 0 ) = TM;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void* MakeRotationMatrix( Rotator Rotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MakeRotationMatrix" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = Rotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* MakeRotationTranslationMatrix( Vector Translation, Rotator Rotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MakeRotationTranslationMatrix" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = Translation;
				*( Rotator* )( params + 12 ) = Rotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			Vector InverseTransformNormal( void* TM, Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.InverseTransformNormal" );
				byte *params = ( byte* )( malloc( 76 ) );
				*( void** )( params + 0 ) = TM;
				*( Vector* )( params + 64 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector TransformNormal( void* TM, Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.TransformNormal" );
				byte *params = ( byte* )( malloc( 76 ) );
				*( void** )( params + 0 ) = TM;
				*( Vector* )( params + 64 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector InverseTransformVector( void* TM, Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.InverseTransformVector" );
				byte *params = ( byte* )( malloc( 76 ) );
				*( void** )( params + 0 ) = TM;
				*( Vector* )( params + 64 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector TransformVector( void* TM, Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.TransformVector" );
				byte *params = ( byte* )( malloc( 76 ) );
				*( void** )( params + 0 ) = TM;
				*( Vector* )( params + 64 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void* Multiply_MatrixMatrix( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_MatrixMatrix" );
				byte *params = ( byte* )( malloc( 128 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 64 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool NotEqual_NameName( ScriptName A, ScriptName B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_NameName" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = A;
				*( ScriptName* )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_NameName( ScriptName A, ScriptName B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_NameName" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = A;
				*( ScriptName* )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsA( ScriptName ClassName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.IsA" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ClassName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ClassIsChildOf( ScriptClass* TestClass, ScriptClass* ParentClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ClassIsChildOf" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = TestClass;
				*( ScriptClass** )( params + 4 ) = ParentClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NotEqual_InterfaceInterface(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_InterfaceInterface" );
				byte *params = ( byte* )( malloc( 16 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_InterfaceInterface(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_InterfaceInterface" );
				byte *params = ( byte* )( malloc( 16 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NotEqual_ObjectObject( class Object* A, class Object* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_ObjectObject" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Object** )( params + 0 ) = A;
				*( class Object** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_ObjectObject( class Object* A, class Object* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_ObjectObject" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Object** )( params + 0 ) = A;
				*( class Object** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > PathName( class Object* CheckObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.PathName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )( params + 0 ) = CheckObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void* SplitString( ScriptArray< wchar_t > Source, ScriptArray< wchar_t > Delimiter, bool bCullEmpty )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SplitString" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Source;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Delimiter;
				*( bool* )( params + 24 ) = bCullEmpty;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void JoinArray( ScriptArray< wchar_t > &out_Result, ScriptArray< wchar_t > delim, bool bIgnoreBlanks )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.JoinArray" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptArray< wchar_t >* )( params + 12 ) = out_Result;
				*( ScriptArray< wchar_t >* )( params + 24 ) = delim;
				*( bool* )( params + 36 ) = bIgnoreBlanks;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Result = *( ScriptArray< wchar_t >* )( params + 12 );
			}

			ScriptArray< wchar_t > GetRightMost( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetRightMost" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > ConcatEqual_StrStr( ScriptArray< wchar_t > &A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ConcatEqual_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Split( ScriptArray< wchar_t > Text, ScriptArray< wchar_t > SplitStr, bool bOmitSplitStr )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Split" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				*( ScriptArray< wchar_t >* )( params + 12 ) = SplitStr;
				*( bool* )( params + 24 ) = bOmitSplitStr;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Repl( ScriptArray< wchar_t > Src, ScriptArray< wchar_t > Match, ScriptArray< wchar_t > With, bool bCaseSensitive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Repl" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Src;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Match;
				*( ScriptArray< wchar_t >* )( params + 24 ) = With;
				*( bool* )( params + 36 ) = bCaseSensitive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			int Asc( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Asc" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Chr( int I )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Chr" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = I;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Locs( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Locs" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Caps( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Caps" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Right( ScriptArray< wchar_t > S, int I )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Right" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				*( int* )( params + 12 ) = I;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Left( ScriptArray< wchar_t > S, int I )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Left" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				*( int* )( params + 12 ) = I;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Mid( ScriptArray< wchar_t > S, int I, int J )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Mid" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				*( int* )( params + 12 ) = I;
				*( int* )( params + 16 ) = J;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			int InStr( ScriptArray< wchar_t > S, ScriptArray< wchar_t > T, bool bSearchFromRight, bool bIgnoreCase, int StartPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.InStr" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				*( ScriptArray< wchar_t >* )( params + 12 ) = T;
				*( bool* )( params + 24 ) = bSearchFromRight;
				*( bool* )( params + 28 ) = bIgnoreCase;
				*( int* )( params + 32 ) = StartPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Len( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Len" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > SubtractEqual_StrStr( ScriptArray< wchar_t > &A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractEqual_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > AtEqual_StrStr( ScriptArray< wchar_t > &A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AtEqual_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool ComplementEqual_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ComplementEqual_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NotEqual_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GreaterEqual_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GreaterEqual_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LessEqual_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.LessEqual_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Greater_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Greater_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Less_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Less_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > At_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.At_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > Concat_StrStr( ScriptArray< wchar_t > A, ScriptArray< wchar_t > B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Concat_StrStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = A;
				*( ScriptArray< wchar_t >* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			Rotator MakeRotator( int Pitch, int Yaw, int Roll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MakeRotator" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = Pitch;
				*( int* )( params + 4 ) = Yaw;
				*( int* )( params + 8 ) = Roll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool SClampRotAxis( float DeltaTime, int ViewAxis, int &out_DeltaViewAxis, int MaxLimit, int MinLimit, float InterpolationSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SClampRotAxis" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( int* )( params + 4 ) = ViewAxis;
				*( int* )( params + 8 ) = out_DeltaViewAxis;
				*( int* )( params + 12 ) = MaxLimit;
				*( int* )( params + 16 ) = MinLimit;
				*( float* )( params + 20 ) = InterpolationSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_DeltaViewAxis = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			int ClampRotAxisFromRange( int Current, int Min, int Max )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ClampRotAxisFromRange" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = Current;
				*( int* )( params + 4 ) = Min;
				*( int* )( params + 8 ) = Max;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int NormalizeRotAxis( int Angle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NormalizeRotAxis" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Angle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float FInterpTo( float Current, float Target, float DeltaTime, float InterpSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FInterpTo" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = Current;
				*( float* )( params + 4 ) = Target;
				*( float* )( params + 8 ) = DeltaTime;
				*( float* )( params + 12 ) = InterpSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int ClampRotAxisFromBase( int Current, int Center, int MaxDelta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ClampRotAxisFromBase" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = Current;
				*( int* )( params + 4 ) = Center;
				*( int* )( params + 8 ) = MaxDelta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ClampRotAxis( int ViewAxis, int &out_DeltaViewAxis, int MaxLimit, int MinLimit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ClampRotAxis" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = ViewAxis;
				*( int* )( params + 4 ) = out_DeltaViewAxis;
				*( int* )( params + 8 ) = MaxLimit;
				*( int* )( params + 12 ) = MinLimit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_DeltaViewAxis = *( int* )( params + 4 );
			}

			float RSize( Rotator R )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.RSize" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = R;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float RDiff( Rotator A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.RDiff" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Rotator RInterpTo( Rotator Current, Rotator Target, float DeltaTime, float InterpSpeed, bool bConstantInterpSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.RInterpTo" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Rotator* )( params + 0 ) = Current;
				*( Rotator* )( params + 12 ) = Target;
				*( float* )( params + 24 ) = DeltaTime;
				*( float* )( params + 28 ) = InterpSpeed;
				*( bool* )( params + 32 ) = bConstantInterpSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator RTransform( Rotator R, Rotator RBasis )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.RTransform" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = R;
				*( Rotator* )( params + 12 ) = RBasis;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator RSmerp( Rotator A, Rotator B, float Alpha, bool bShortestPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.RSmerp" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				*( float* )( params + 24 ) = Alpha;
				*( bool* )( params + 28 ) = bShortestPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator RLerp( Rotator A, Rotator B, float Alpha, bool bShortestPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.RLerp" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				*( float* )( params + 24 ) = Alpha;
				*( bool* )( params + 28 ) = bShortestPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator Normalize( Rotator Rot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Normalize" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = Rot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator OrthoRotation( Vector X, Vector Y, Vector Z )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.OrthoRotation" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )( params + 0 ) = X;
				*( Vector* )( params + 12 ) = Y;
				*( Vector* )( params + 24 ) = Z;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator RotRand( bool bRoll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.RotRand" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bRoll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Vector GetRotatorAxis( Rotator A, int Axis )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetRotatorAxis" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = A;
				*( int* )( params + 12 ) = Axis;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void GetUnAxes( Rotator A, Vector &X, Vector &Y, Vector &Z )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetUnAxes" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = X;
				*( Vector* )( params + 24 ) = Y;
				*( Vector* )( params + 36 ) = Z;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				X = *( Vector* )( params + 12 );
				Y = *( Vector* )( params + 24 );
				Z = *( Vector* )( params + 36 );
			}

			void GetAxes( Rotator A, Vector &X, Vector &Y, Vector &Z )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GetAxes" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = X;
				*( Vector* )( params + 24 ) = Y;
				*( Vector* )( params + 36 ) = Z;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				X = *( Vector* )( params + 12 );
				Y = *( Vector* )( params + 24 );
				Z = *( Vector* )( params + 36 );
			}

			bool ClockwiseFrom_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ClockwiseFrom_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Rotator SubtractEqual_RotatorRotator( Rotator &A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractEqual_RotatorRotator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Rotator* )( params + 0 );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator AddEqual_RotatorRotator( Rotator &A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddEqual_RotatorRotator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Rotator* )( params + 0 );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator Subtract_RotatorRotator( Rotator A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_RotatorRotator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator Add_RotatorRotator( Rotator A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Add_RotatorRotator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator DivideEqual_RotatorFloat( Rotator &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DivideEqual_RotatorFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = A;
				*( float* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Rotator* )( params + 0 );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator MultiplyEqual_RotatorFloat( Rotator &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyEqual_RotatorFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = A;
				*( float* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Rotator* )( params + 0 );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator Divide_RotatorFloat( Rotator A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Divide_RotatorFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = A;
				*( float* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator Multiply_FloatRotator( float A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_FloatRotator" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = A;
				*( Rotator* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator Multiply_RotatorFloat( Rotator A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_RotatorFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = A;
				*( float* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool NotEqual_RotatorRotator( Rotator A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_RotatorRotator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_RotatorRotator( Rotator A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_RotatorRotator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool InCylinder( Vector Origin, Rotator Dir, float Width, Vector A, bool bIgnoreZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.InCylinder" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( Vector* )( params + 0 ) = Origin;
				*( Rotator* )( params + 12 ) = Dir;
				*( float* )( params + 24 ) = Width;
				*( Vector* )( params + 28 ) = A;
				*( bool* )( params + 40 ) = bIgnoreZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float NoZDot( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NoZDot" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Vector ClampLength( Vector V, float MaxLength )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ClampLength" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = V;
				*( float* )( params + 12 ) = MaxLength;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector VInterpTo( Vector Current, Vector Target, float DeltaTime, float InterpSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VInterpTo" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( Vector* )( params + 0 ) = Current;
				*( Vector* )( params + 12 ) = Target;
				*( float* )( params + 24 ) = DeltaTime;
				*( float* )( params + 28 ) = InterpSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool IsZero( Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.IsZero" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector ProjectOnTo( Vector X, Vector Y )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ProjectOnTo" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = X;
				*( Vector* )( params + 12 ) = Y;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector MirrorVectorByNormal( Vector InVect, Vector InNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MirrorVectorByNormal" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = InVect;
				*( Vector* )( params + 12 ) = InNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector VRandCone2( Vector Dir, float HorizontalConeHalfAngleRadians, float VerticalConeHalfAngleRadians )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VRandCone2" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )( params + 0 ) = Dir;
				*( float* )( params + 12 ) = HorizontalConeHalfAngleRadians;
				*( float* )( params + 16 ) = VerticalConeHalfAngleRadians;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector VRandCone( Vector Dir, float ConeHalfAngleRadians )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VRandCone" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = Dir;
				*( float* )( params + 12 ) = ConeHalfAngleRadians;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector VRand(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VRand" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector VSmerp( Vector A, Vector B, float Alpha )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VSmerp" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				*( float* )( params + 24 ) = Alpha;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector VLerp( Vector A, Vector B, float Alpha )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VLerp" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				*( float* )( params + 24 ) = Alpha;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Normal( Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Normal" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float VSizeSq2D( Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VSizeSq2D" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float VSizeSq( Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VSizeSq" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float VSize2D( Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VSize2D" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float VSize( Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.VSize" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Vector SubtractEqual_VectorVector( Vector &A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractEqual_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Vector* )( params + 0 );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector AddEqual_VectorVector( Vector &A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddEqual_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Vector* )( params + 0 );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector DivideEqual_VectorFloat( Vector &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DivideEqual_VectorFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = A;
				*( float* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Vector* )( params + 0 );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector MultiplyEqual_VectorVector( Vector &A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyEqual_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Vector* )( params + 0 );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector MultiplyEqual_VectorFloat( Vector &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyEqual_VectorFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = A;
				*( float* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( Vector* )( params + 0 );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Cross_VectorVector( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Cross_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float Dot_VectorVector( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Dot_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool NotEqual_VectorVector( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_VectorVector( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector GreaterGreater_VectorRotator( Vector A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GreaterGreater_VectorRotator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector LessLess_VectorRotator( Vector A, Rotator B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.LessLess_VectorRotator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Rotator* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Subtract_VectorVector( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Add_VectorVector( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Add_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Divide_VectorFloat( Vector A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Divide_VectorFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = A;
				*( float* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Multiply_VectorVector( Vector A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_VectorVector" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = A;
				*( Vector* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Multiply_FloatVector( float A, Vector B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_FloatVector" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = A;
				*( Vector* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Multiply_VectorFloat( Vector A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_VectorFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = A;
				*( float* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector Subtract_PreVector( Vector A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_PreVector" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float FInterpConstantTo( float Current, float Target, float DeltaTime, float InterpSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FInterpConstantTo" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = Current;
				*( float* )( params + 4 ) = Target;
				*( float* )( params + 8 ) = DeltaTime;
				*( float* )( params + 12 ) = InterpSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FPctByRange( float Value, float InMin, float InMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FPctByRange" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = Value;
				*( float* )( params + 4 ) = InMin;
				*( float* )( params + 8 ) = InMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float RandRange( float InMin, float InMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.RandRange" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = InMin;
				*( float* )( params + 4 ) = InMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FInterpEaseInOut( float A, float B, float Alpha, float Exp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FInterpEaseInOut" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				*( float* )( params + 8 ) = Alpha;
				*( float* )( params + 12 ) = Exp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FInterpEaseOut( float A, float B, float Alpha, float Exp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FInterpEaseOut" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				*( float* )( params + 8 ) = Alpha;
				*( float* )( params + 12 ) = Exp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FInterpEaseIn( float A, float B, float Alpha, float Exp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FInterpEaseIn" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				*( float* )( params + 8 ) = Alpha;
				*( float* )( params + 12 ) = Exp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FCubicInterp( float P0, float T0, float P1, float T1, float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FCubicInterp" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )( params + 0 ) = P0;
				*( float* )( params + 4 ) = T0;
				*( float* )( params + 8 ) = P1;
				*( float* )( params + 12 ) = T1;
				*( float* )( params + 16 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int FCeil( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FCeil" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int FFloor( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FFloor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Round( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Round" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float Lerp( float A, float B, float Alpha )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Lerp" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				*( float* )( params + 8 ) = Alpha;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FClamp( float V, float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FClamp" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = V;
				*( float* )( params + 4 ) = A;
				*( float* )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FMax( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FMax" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FMin( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FMin" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float FRand(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.FRand" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Square( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Square" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Sqrt( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Sqrt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Loge( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Loge" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Exp( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Exp" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Atan2( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Atan2" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Atan( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Atan" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Tan( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Tan" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Cos( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Cos" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Asin( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Asin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Sin( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Sin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Abs( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Abs" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float SubtractEqual_FloatFloat( float &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( float* )( params + 0 );
				return *( float* )( params + function->return_val_offset() );
			}

			float AddEqual_FloatFloat( float &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( float* )( params + 0 );
				return *( float* )( params + function->return_val_offset() );
			}

			float DivideEqual_FloatFloat( float &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DivideEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( float* )( params + 0 );
				return *( float* )( params + function->return_val_offset() );
			}

			float MultiplyEqual_FloatFloat( float &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( float* )( params + 0 );
				return *( float* )( params + function->return_val_offset() );
			}

			bool NotEqual_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ComplementEqual_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ComplementEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GreaterEqual_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GreaterEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LessEqual_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.LessEqual_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Greater_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Greater_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Less_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Less_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float Subtract_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Add_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Add_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Percent_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Percent_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Divide_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Divide_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Multiply_FloatFloat( float A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float MultiplyMultiply_FloatFloat( float Base, float Exp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyMultiply_FloatFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = Base;
				*( float* )( params + 4 ) = Exp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float Subtract_PreFloat( float A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_PreFloat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > ToHex( int A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.ToHex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			int Clamp( int V, int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Clamp" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = V;
				*( int* )( params + 4 ) = A;
				*( int* )( params + 8 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Max( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Max" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Min( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Min" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Rand( int Max )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Rand" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Max;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int SubtractSubtract_Int( int &A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractSubtract_Int" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int AddAdd_Int( int &A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddAdd_Int" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int SubtractSubtract_PreInt( int &A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractSubtract_PreInt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int AddAdd_PreInt( int &A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddAdd_PreInt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int SubtractEqual_IntInt( int &A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractEqual_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int AddEqual_IntInt( int &A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddEqual_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int DivideEqual_IntFloat( int &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DivideEqual_IntFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int MultiplyEqual_IntFloat( int &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyEqual_IntFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int Or_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Or_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Xor_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Xor_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int And_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.And_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool NotEqual_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GreaterEqual_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GreaterEqual_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LessEqual_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.LessEqual_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Greater_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Greater_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Less_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Less_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GreaterGreaterGreater_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GreaterGreaterGreater_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GreaterGreater_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.GreaterGreater_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int LessLess_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.LessLess_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Subtract_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Add_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Add_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Percent_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Percent_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Divide_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Divide_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Multiply_IntInt( int A, int B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Multiply_IntInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = A;
				*( int* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Subtract_PreInt( int A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Subtract_PreInt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Complement_PreInt( int A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Complement_PreInt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			byte SubtractSubtract_Byte( byte &A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractSubtract_Byte" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte AddAdd_Byte( byte &A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddAdd_Byte" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte SubtractSubtract_PreByte( byte &A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractSubtract_PreByte" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte AddAdd_PreByte( byte &A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddAdd_PreByte" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte SubtractEqual_ByteByte( byte &A, byte B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.SubtractEqual_ByteByte" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = A;
				*( byte* )( params + 1 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte AddEqual_ByteByte( byte &A, byte B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AddEqual_ByteByte" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = A;
				*( byte* )( params + 1 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte DivideEqual_ByteByte( byte &A, byte B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.DivideEqual_ByteByte" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = A;
				*( byte* )( params + 1 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte MultiplyEqual_ByteFloat( byte &A, float B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyEqual_ByteFloat" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = A;
				*( float* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte MultiplyEqual_ByteByte( byte &A, byte B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.MultiplyEqual_ByteByte" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = A;
				*( byte* )( params + 1 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				A = *( byte* )( params + 0 );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool OrOr_BoolBool( bool A, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.OrOr_BoolBool" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = A;
				*( bool* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool XorXor_BoolBool( bool A, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.XorXor_BoolBool" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = A;
				*( bool* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AndAnd_BoolBool( bool A, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.AndAnd_BoolBool" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = A;
				*( bool* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NotEqual_BoolBool( bool A, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.NotEqual_BoolBool" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = A;
				*( bool* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EqualEqual_BoolBool( bool A, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.EqualEqual_BoolBool" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = A;
				*( bool* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Not_PreBool( bool A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Object.Not_PreBool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, ObjectInternalInteger, 0xFFFFFFFF )
			ADD_OBJECT( Object, Linker )
			ADD_VAR( ::IntProperty, NetIndex, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, Class )
			ADD_OBJECT( Object, ObjectArchetype )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
