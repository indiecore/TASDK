#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage : public GFxObject
	{
	public:
			ADD_VAR( ::StrProperty, HelpButtonYLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonXLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonBLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonALabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonYKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonXKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonBKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonAKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PageLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PageLabelOverride, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowTribesLogo, 0x200 )
			ADD_VAR( ::BoolProperty, bParentLocked, 0x100 )
			ADD_VAR( ::BoolProperty, bHasModifiers, 0x80 )
			ADD_VAR( ::BoolProperty, bCreated, 0x40 )
			ADD_VAR( ::BoolProperty, bActive, 0x20 )
			ADD_VAR( ::BoolProperty, bAllowBack, 0x10 )
			ADD_VAR( ::BoolProperty, bEndOfLine, 0x8 )
			ADD_VAR( ::BoolProperty, bRemoveOption, 0x4 )
			ADD_VAR( ::BoolProperty, bModifyOption, 0x2 )
			ADD_VAR( ::BoolProperty, bFillingFocus, 0x1 )
			ADD_VAR( ::IntProperty, LoadoutEquipType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LoadoutClassId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NewAction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OptionCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ActiveIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ScrollIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HelpButtonYNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HelpButtonXNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HelpButtonBNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HelpButtonANum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GoBack, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ActiveLoadout, 0xFFFFFFFF )
			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxTrAction* AddAction(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.AddAction" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxTrAction** )( params + function->return_val_offset() );
			}

			class GFxTrAction* AddActionNumber( int ActionNumber )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.AddActionNumber" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionNumber;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxTrAction** )( params + function->return_val_offset() );
			}

			class GFxTrAction* AddActionString( ScriptArray< wchar_t > ActionString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.AddActionString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = ActionString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxTrAction** )( params + function->return_val_offset() );
			}

			class GFxTrAction* AddActionPage( class GFxTrPage* ActionPage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.AddActionPage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxTrPage** )params = ActionPage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxTrAction** )( params + function->return_val_offset() );
			}

			class GFxTrAction* AddActionSet( class GFxTrPage* ActionPage, int ActionNumber, ScriptArray< wchar_t > ActionString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.AddActionSet" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class GFxTrPage** )params = ActionPage;
				*( int* )( params + 4 ) = ActionNumber;
				*( ScriptArray< wchar_t >* )( params + 8 ) = ActionString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxTrAction** )( params + function->return_val_offset() );
			}

			int TakeFocus( int ActionIndex, class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.TakeFocus" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ActionIndex;
				*( class GFxObject** )( params + 4 ) = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int TakeAction( int ActionIndex, class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.TakeAction" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ActionIndex;
				*( class GFxObject** )( params + 4 ) = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int ModifyAction( int ActionIndex, class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ModifyAction" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ActionIndex;
				*( class GFxObject** )( params + 4 ) = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ModifyFocus( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ModifyFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HelpButton( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.HelpButton" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpecialAction( class GFxTrAction* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.SpecialAction" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxTrAction** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopupData( class GFxObject* Obj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.PopupData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Obj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopupComplete( int Action, ScriptArray< wchar_t > TextInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.PopupComplete" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Action;
				*( ScriptArray< wchar_t >* )( params + 4 ) = TextInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillData( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* FillOptions( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillOptions" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			bool IsOwned( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.IsOwned" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckPurchasable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.CheckPurchasable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsEquipMaxed( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.IsEquipMaxed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class GFxObject* FillOption( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillOption" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			class GFxObject* FillDefault(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillDefault" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			bool CheckUpgrades( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.CheckUpgrades" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckPricing( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.CheckPricing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class GFxObject* FillUpgrades( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillUpgrades" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			class GFxObject* FillPricing( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillPricing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			void CheckDescription( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.CheckDescription" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* FillDescription( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillDescription" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			void FillPage( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillPage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearActions(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ClearActions" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowModel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ShowModel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* FillClass( int ClassId, int ActionIndex, bool bShowActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillClass" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = ActionIndex;
				*( bool* )( params + 8 ) = bShowActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			class GFxObject* FillEquipTypes( int EquipId, int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.FillEquipTypes" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = EquipId;
				*( int* )( params + 4 ) = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			bool NewClassEquip( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.NewClassEquip" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NewClassUpgrade( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.NewClassUpgrade" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NewEquipUpgrade( int EquipId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.NewEquipUpgrade" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = EquipId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RevertSetting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.RevertSetting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPurchaseSuccess(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.OnPurchaseSuccess" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActionUp(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ActionUp" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActionDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ActionDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshButtons(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.RefreshButtons" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KeyEvent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.KeyEvent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateDealTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.UpdateDealTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateQueueTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.UpdateQueueTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProfileUp( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ProfileUp" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProfileDown( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ProfileDown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetRunaway(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ResetRunaway" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowReticule( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.ShowReticule" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveReticule( class GFxObject* Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.SaveReticule" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnClose(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage.OnClose" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
