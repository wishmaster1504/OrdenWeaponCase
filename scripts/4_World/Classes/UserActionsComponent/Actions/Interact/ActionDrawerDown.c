class ActionDrawerDown: ActionInteractBase
{
	void ActionDrawerDown()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override string GetText()
	{
		return "Опустить ручку";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			Orden_Weapon_Case ntarget = Orden_Weapon_Case.Cast( target_object );
			if( ntarget )
			{
				if ( !ntarget.IsOpen() && ntarget.isDrawerUP() ) 
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		Orden_Weapon_Case ntarget = Orden_Weapon_Case.Cast( target_object );
		
		if( ntarget )
		{ 
			ntarget.DrawerDown();
		}
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		Orden_Weapon_Case ntarget = Orden_Weapon_Case.Cast( target_object );
		if( ntarget )
		{ 
			ntarget.SoundSynchRemoteResetDrawer();
		}
	}
}