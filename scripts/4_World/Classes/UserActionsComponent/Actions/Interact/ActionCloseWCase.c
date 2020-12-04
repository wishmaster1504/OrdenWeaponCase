class ActionCloseWCase: ActionInteractBase
{
	void ActionCloseWCase()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override string GetText()
	{
		return "Закрыть кейс";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			Orden_Weapon_Case ntarget = Orden_Weapon_Case.Cast( target_object );
			if( ntarget )
			{
				if ( ntarget.IsOpen() )
				//if ( !ntarget.IsLocked() && ntarget.IsOpen() )
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
			ntarget.DetermineAction(action_data.m_Player);
		}
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		Orden_Weapon_Case ntarget = Orden_Weapon_Case.Cast( target_object );
		if( ntarget )
		{
			ntarget.SoundSynchRemoteReset();
		}
	}
}