#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshGoal_GenericFilterContainer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshGoal_GenericFilterContainer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshGoal_GenericFilterContainer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshGoal_GenericFilterContainer : public NavMeshPathGoalEvaluator
	{
	public:
			ADD_OBJECT( NavigationHandle, MyNavigationHandle )
			class NavMeshGoal_GenericFilterContainer* CreateAndAddFilterToNavHandle( class NavigationHandle* NavHandle, int InMaxPathVisits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_GenericFilterContainer.CreateAndAddFilterToNavHandle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavigationHandle** )( params + 0 ) = NavHandle;
				*( int* )( params + 4 ) = InMaxPathVisits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavMeshGoal_GenericFilterContainer** )( params + function->return_val_offset() );
			}

			class NavMeshGoal_Filter* GetFilterOfType( ScriptClass* Filter_Class )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_GenericFilterContainer.GetFilterOfType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = Filter_Class;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavMeshGoal_Filter** )( params + function->return_val_offset() );
			}

			Vector GetGoalPoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_GenericFilterContainer.GetGoalPoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_GenericFilterContainer.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
