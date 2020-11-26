private    ref Ultima_Server_Class_Logs    Log = new Ultima_Server_Class_Logs();
//WrtiteToLogFile("MESSAGE");

class Orden_Weapon_Case : Container_Base
{ 
	private bool m_Drawer_Handle_Up = false; // ручка кейса опущена
	private ref Timer m_BarrelOpener;
	protected ref OpenableBehaviour m_Openable; 
	private bool g_WtrLog = true; // true - логировать (отключить для релиза)
	private string g_filePath = "$profile:WishLogFile.txt"; // C:\Users\Алексей\AppData\Local\DayZ\WishLogFile.txt

	
	void Orden_Weapon_Case()
	{
		m_BarrelOpener = new Timer();

		m_Openable = new OpenableBehaviour(false);
		
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened"); 
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsPlaceSound");
		RegisterNetSyncVariableBool("m_Drawer_Handle_Up");
	}
	
	override void EEInit()
	{
		super.EEInit();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}
	
	/*override bool IsHeavyBehaviour()
	{
		return true;
	}*/
	
	override int GetDamageSystemVersionChange()
	{
		return 110;
	}
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		
		ctx.Write( m_Openable.IsOpened() ); 
		ctx.Write( m_Drawer_Handle_Up );		
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		bool opened;
		//bool locked;
		bool drawer_Handle; 
		 
		
		if ( version >= 110 && !ctx.Read( opened ) && !ctx.Read( drawer_Handle )) //&& !ctx.Read( locked ) )
		{
			return false;
		}
		
		if ( opened )
		{
			Open();
		}
		else
		{
			Close();
		}
		
		 
		if (drawer_Handle)
		{
		   DrawerUp();	 
		}
		else
		{
		   DrawerDown();
		}
	
		
		return true;
	}
	 

	override void Open()
	{ 

		m_Openable.Open();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		SoundSynchRemote();
		  
		//SetSynchDirty(); //! called also in SoundSynchRemote - TODO
		 
		UpdateVisualState();
		   
	}

	override void Close()
	{
		 
		m_Openable.Close();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		SoundSynchRemote(); 

		//SetSynchDirty(); //! called also in SoundSynchRemote - TODO
		 
		UpdateVisualState();
		   
	}

	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}

	protected void UpdateVisualState()
	{ 
		if ( IsOpen() )
		{
			SetAnimationPhase("Clap1",1); 
			//[] spawn {sleep 0.5;};
			//MySleepFunc(); 
			SetAnimationPhase("Clap2",1); 
			SetAnimationPhase("Clap3",1); 
			SetAnimationPhase("Clap4",1); 
			SetAnimationPhase("Door1",0);
		}
		else
		{
			SetAnimationPhase("Door1",1);
			SetAnimationPhase("Clap4",0);
			SetAnimationPhase("Clap3",0);
			SetAnimationPhase("Clap2",0);
			SetAnimationPhase("Clap1",0);
		}
		 
		//  
		if (isDrawerUP())
		{
			SetAnimationPhase("Drawer_Handle",1);
		}
		else
		{
			SetAnimationPhase("Drawer_Handle",0);
		}
		 
	}
    int GetCurrentTime()
	{
		int hour, minute, second;
		GetHourMinuteSecond(hour, minute, second);
		//string time = hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
		return hour*3600 + minute*60 + second;
	}
	
	void MySleepFunc()
	{
		int curTime, stopTime;
		
		curTime = GetCurrentTime();
		stopTime = curTime + 1;
		while (curTime <= stopTime) 
		{
			curTime = GetCurrentTime();
		}
	}

	string GetCurTime()
	{
		int hour, minute, second;
		GetHourMinuteSecond(hour, minute, second);
		string time = hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
		return time;
	}
	
	override void OnVariablesSynchronized()
	{
		  
		super.OnVariablesSynchronized();
				
		if ( IsPlaceSound() )
		{
			PlayPlaceSound();
		}
		else
		{
			if ( IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
			{
				 
				SoundWeaponCaseOpenPlay();
				
			}
			
			if ( !IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
			{
				 
				SoundWeaponCaseClosePlay();

			}
			 
			// звук поднятия или опускания ручки
			if (isDrawerUP() && IsSoundSynchRemoteDrawer() && !IsBeingPlaced() ) 
			{
				 
				SoundWeaponCaseDrawerUpPlay();

			}
			if (!isDrawerUP() && IsSoundSynchRemoteDrawer() && !IsBeingPlaced() ) 
			{
				 
				SoundWeaponCaseDrawerDownPlay();

			}
		}
		
		UpdateVisualState();

		//WrtiteToLogFile("FUNCTION OnVariablesSynchronized END");

	}
	
	void SoundWeaponCaseOpenPlay()
	{
		WrtiteToLogFile("FUNCTION SoundWeaponCaseOpenPlay START");
		 
		EffectSound sound =	SEffectManager.PlaySound( "weapon_case_open_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );

		WrtiteToLogFile("FUNCTION SoundWeaponCaseOpenPlay END");
	}

	void SoundWeaponCaseClosePlay()
	{
		WrtiteToLogFile("FUNCTION SoundWeaponCaseClosePlay START");
		 
		EffectSound sound =	SEffectManager.PlaySound( "weapon_case_close_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );

		WrtiteToLogFile("FUNCTION SoundWeaponCaseClosePlay END");
	}
	 
	void SoundWeaponCaseDrawerUpPlay()
	{
		WrtiteToLogFile("FUNCTION SoundWeaponCaseDrawerUpPlay START");
		 
		EffectSound sound =	SEffectManager.PlaySound( "weapon_case_drawerup_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
		//SetDrawerActionEnabled(false);

		WrtiteToLogFile("FUNCTION SoundWeaponCaseDrawerUpPlay END");
	}

	void SoundWeaponCaseDrawerDownPlay()
	{
		WrtiteToLogFile("FUNCTION SoundWeaponCaseDrawerDownPlay START");  

		EffectSound sound =	SEffectManager.PlaySound( "weapon_case_drawerdown_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
		//SetDrawerActionEnabled(false);

		WrtiteToLogFile("FUNCTION SoundWeaponCaseDrawerDownPlay END");

	}
	 
	void DetermineAction ( PlayerBase player )
	{
		Close();
	}		
	
	override bool CanPutInCargo( EntityAI parent )
	{
		//if( !super.CanPutInCargo(parent) ) {return false;}		
		//if ( GetNumberOfItems() == 0 && !IsOpen() )
		//{
		//	return true;
		//}
		return false;
	}
	
	override bool CanPutIntoHands(EntityAI parent)
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		// кейс закрыт, ручка поднята
		if ( GetNumberOfItems() == 0 && !IsOpen() && isDrawerUP() ) 
		{
			return true;
		}
		
		return false;

	}
	
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if ( IsOpen() )
			return super.CanReceiveItemIntoCargo( item );
		
		return false;
	}
	
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}
	
	
	bool isDrawerUP()
	{
	  
		return m_Drawer_Handle_Up;

	}
	
	
	void DrawerUp()
	{
		WrtiteToLogFile("FUNCTION DrawerUp START");

		m_Drawer_Handle_Up = true; 
		//SoundSynchRemote();
		SoundSynchRemoteDrawer();

		UpdateVisualState();

		WrtiteToLogFile("FUNCTION DrawerUp END");

	}
	
	void DrawerDown()
	{
		WrtiteToLogFile("FUNCTION DrawerDown START");

		m_Drawer_Handle_Up = false; 
		//SoundSynchRemote();
		SoundSynchRemoteDrawer();

		UpdateVisualState();

		WrtiteToLogFile("FUNCTION DrawerDown END");

	}
	  
	string RetStringValFlag(bool value)
	{ 
		if (value)
		{
			return "TRUE";
		}
		else
		{
			return "FALSE";
		}

	}


	// Запись в свой лог файл
	void WrtiteToLogFile(string message)
	{
		if (g_WtrLog) // если включено логирование
		{
			Log.SaveLog(g_filePath, GetCurTime() + "  :  " + message);
		}
	}

	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{		
		super.OnPlacementComplete( player );
			
		SetIsPlaceSound( true );
	}
	
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionOpenBox);
		AddAction(ActionCloseBox); 	
		AddAction(ActionDrawerUp);		
		AddAction(ActionDrawerDown);	
		AddAction(ActionTakeItemToHands);	
	}

};
