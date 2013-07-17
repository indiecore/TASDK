#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Font." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Font." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Font." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Font : public Object
	{
	public:
			ADD_VAR( ::IntProperty, NumCharacters, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Kerning, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Leading, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Descent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Ascent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EmScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IsRemapped, 0xFFFFFFFF )
			int GetResolutionPageIndex( float HeightTest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Font.GetResolutionPageIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = HeightTest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float GetScalingFactor( float HeightTest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Font.GetScalingFactor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = HeightTest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetAuthoredViewportHeight( float ViewportHeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Font.GetAuthoredViewportHeight" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ViewportHeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetMaxCharHeight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Font.GetMaxCharHeight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void GetStringHeightAndWidth( ScriptArray< wchar_t > &InString, int &Height, int &Width )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Font.GetStringHeightAndWidth" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = InString;
				*( int* )( params + 12 ) = Height;
				*( int* )( params + 16 ) = Width;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InString = *( ScriptArray< wchar_t >* )( params + 0 );
				Height = *( int* )( params + 12 );
				Width = *( int* )( params + 16 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
