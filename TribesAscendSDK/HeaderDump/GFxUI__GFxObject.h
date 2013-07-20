#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxObject." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxObject." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxObject." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxObject : public Object
	{
	public:
			ADD_VAR( ::IntProperty, Value, 0xFFFFFFFF )
			void* Get( ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.Get" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool GetBool( ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetBool" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetFloat( ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetString( ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			class GFxObject* GetObject( ScriptArray< wchar_t > Member, ScriptClass* Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetObject" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				*( ScriptClass** )( params + 12 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			void Set( ScriptArray< wchar_t > Member, void* Arg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.Set" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				*( void** )( params + 12 ) = Arg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBool( ScriptArray< wchar_t > Member, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetBool" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				*( bool* )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFloat( ScriptArray< wchar_t > Member, float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				*( float* )( params + 12 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetString( ScriptArray< wchar_t > Member, ScriptArray< wchar_t > S, class TranslationContext* InContext )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetString" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				*( ScriptArray< wchar_t >* )( params + 12 ) = S;
				*( class TranslationContext** )( params + 24 ) = InContext;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetObject( ScriptArray< wchar_t > Member, class GFxObject* val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetObject" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				*( class GFxObject** )( params + 12 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFunction( ScriptArray< wchar_t > Member, class Object* context, ScriptName fname )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetFunction" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				*( class Object** )( params + 12 ) = context;
				*( ScriptName* )( params + 16 ) = fname;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > TranslateString( ScriptArray< wchar_t > StringToTranslate, class TranslationContext* InContext )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.TranslateString" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = StringToTranslate;
				*( class TranslationContext** )( params + 12 ) = InContext;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void* GetDisplayInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetDisplayInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool GetPosition( float &X, float &Y )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetPosition" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = X;
				*( float* )( params + 4 ) = Y;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				X = *( float* )params;
				Y = *( float* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* GetColorTransform(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetColorTransform" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* GetDisplayMatrix(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetDisplayMatrix" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void SetDisplayInfo( void* D )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetDisplayInfo" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( void** )params = D;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPosition( float X, float Y )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetPosition" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = X;
				*( float* )( params + 4 ) = Y;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetColorTransform( void* cxform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetColorTransform" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )params = cxform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDisplayMatrix( void* M )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetDisplayMatrix" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( void** )params = M;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDisplayMatrix3D( void* M )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetDisplayMatrix3D" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( void** )params = M;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVisible( bool Visible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetVisible" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = Visible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetText(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetText" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SetText( ScriptArray< wchar_t > Text, class TranslationContext* InContext )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetText" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Text;
				*( class TranslationContext** )( params + 12 ) = InContext;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetElement( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElement" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			class GFxObject* GetElementObject( int Index, ScriptClass* Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementObject" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Index;
				*( ScriptClass** )( params + 4 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			bool GetElementBool( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementBool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetElementFloat( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementFloat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetElementString( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementString" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SetElement( int Index, void* Arg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElement" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = Index;
				*( void** )( params + 4 ) = Arg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementObject( int Index, class GFxObject* val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementObject" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Index;
				*( class GFxObject** )( params + 4 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementBool( int Index, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementBool" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Index;
				*( bool* )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementFloat( int Index, float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Index;
				*( float* )( params + 4 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementString( int Index, ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementString" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetElementDisplayInfo( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementDisplayInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* GetElementDisplayMatrix( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementDisplayMatrix" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void SetElementDisplayInfo( int Index, void* D )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementDisplayInfo" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( int* )params = Index;
				*( void** )( params + 4 ) = D;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementDisplayMatrix( int Index, void* M )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementDisplayMatrix" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )params = Index;
				*( void** )( params + 16 ) = M;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementVisible( int Index, bool Visible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementVisible" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Index;
				*( bool* )( params + 4 ) = Visible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementPosition( int Index, float X, float Y )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementPosition" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = Index;
				*( float* )( params + 4 ) = X;
				*( float* )( params + 8 ) = Y;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementColorTransform( int Index, void* cxform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementColorTransform" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( int* )params = Index;
				*( void** )( params + 4 ) = cxform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetElementMember( int Index, ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementMember" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			class GFxObject* GetElementMemberObject( int Index, ScriptArray< wchar_t > Member, ScriptClass* Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementMemberObject" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				*( ScriptClass** )( params + 16 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			bool GetElementMemberBool( int Index, ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementMemberBool" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetElementMemberFloat( int Index, ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementMemberFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetElementMemberString( int Index, ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GetElementMemberString" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SetElementMember( int Index, ScriptArray< wchar_t > Member, void* Arg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementMember" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				*( void** )( params + 16 ) = Arg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementMemberObject( int Index, ScriptArray< wchar_t > Member, class GFxObject* val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementMemberObject" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				*( class GFxObject** )( params + 16 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementMemberBool( int Index, ScriptArray< wchar_t > Member, bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementMemberBool" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				*( bool* )( params + 16 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementMemberFloat( int Index, ScriptArray< wchar_t > Member, float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementMemberFloat" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				*( float* )( params + 16 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetElementMemberString( int Index, ScriptArray< wchar_t > Member, ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.SetElementMemberString" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = Index;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				*( ScriptArray< wchar_t >* )( params + 16 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActionScriptSetFunction( ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.ActionScriptSetFunction" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActionScriptSetFunctionOn( class GFxObject* Target, ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.ActionScriptSetFunctionOn" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class GFxObject** )params = Target;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* Invoke( ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.Invoke" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void ActionScriptVoid( ScriptArray< wchar_t > method )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.ActionScriptVoid" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = method;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int ActionScriptInt( ScriptArray< wchar_t > method )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.ActionScriptInt" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = method;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float ActionScriptFloat( ScriptArray< wchar_t > method )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.ActionScriptFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = method;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > ActionScriptString( ScriptArray< wchar_t > method )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.ActionScriptString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = method;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			class GFxObject* ActionScriptObject( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.ActionScriptObject" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			void* ActionScriptArray( ScriptArray< wchar_t > Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.ActionScriptArray" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void GotoAndPlay( ScriptArray< wchar_t > frame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GotoAndPlay" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = frame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GotoAndPlayI( int frame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GotoAndPlayI" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = frame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GotoAndStop( ScriptArray< wchar_t > frame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GotoAndStop" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = frame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GotoAndStopI( int frame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.GotoAndStopI" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = frame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* CreateEmptyMovieClip( ScriptArray< wchar_t > instancename, int Depth, ScriptClass* Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.CreateEmptyMovieClip" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )params = instancename;
				*( int* )( params + 12 ) = Depth;
				*( ScriptClass** )( params + 16 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			class GFxObject* AttachMovie( ScriptArray< wchar_t > symbolname, ScriptArray< wchar_t > instancename, int Depth, ScriptClass* Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.AttachMovie" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptArray< wchar_t >* )params = symbolname;
				*( ScriptArray< wchar_t >* )( params + 12 ) = instancename;
				*( int* )( params + 24 ) = Depth;
				*( ScriptClass** )( params + 28 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.WidgetInitialized" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = WidgetName;
				*( ScriptName* )( params + 8 ) = WidgetPath;
				*( class GFxObject** )( params + 16 ) = Widget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WidgetUnloaded( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxObject.WidgetUnloaded" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = WidgetName;
				*( ScriptName* )( params + 8 ) = WidgetPath;
				*( class GFxObject** )( params + 16 ) = Widget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
