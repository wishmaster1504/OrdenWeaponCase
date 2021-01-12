//private    ref OrdenLogTemplate logFile = new OrdenLogTemplate();
//logFile.WrtiteToLogFile("MESSAGE"); - вызов функции записи в лог

class Orden_Weapon_Case : Container_Base
//class Orden_Weapon_Case : OrdenCaseTemplates
{ 
	private bool m_Drawer_Handle_Up = false; // ручка кейса опущена
	private ref Timer m_BarrelOpener;
	protected ref OpenableBehaviour m_Openable; 
	  
	
	void Orden_Weapon_Case()
	{
		m_BarrelOpener = new Timer();
		 
		m_Openable = new OpenableBehaviour(false);
		
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened"); 
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsPlaceSound");
		RegisterNetSyncVariableBool("m_Drawer_Handle_Up");

		// параметры логирования в файл
		//logFile.SetLogFlag(true); // включаем логирование в файл
		//logFile.SetFilePath("$profile:WishLogFile.txt"); // в свой файл
	}
	
	override void EEInit()
	{
		super.EEInit();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}
	
	
	override int GetDamageSystemVersionChange()
	{
		return 110;
	}
	
	//override void OnStoreSave( ParamsWriteContext ctx )
	//{   
	//	super.OnStoreSave( ctx );
	//	
	//	//ctx.Write( m_Openable.IsOpened() ); 
	//	//ctx.Write( m_Drawer_Handle_Up );		
	//}
	
	//override bool OnStoreLoad( ParamsReadContext ctx, int version )
	//{
	//	if ( !super.OnStoreLoad( ctx, version ) )
	//		return false;

	//	// появляется всегда закрытым
	//	m_Openable.Close();
	//	Close();
	//	DrawerDown();

	//	return true;

	//	
	//	//
	//	//bool opened;
	//	////bool locked;
	//	//bool drawer_Handle; 
	//	// 
	//	//
	//	//if ( version >= 110 && !ctx.Read( opened ) && !ctx.Read( drawer_Handle )) //&& !ctx.Read( locked ) )
	//	//{
	//	//	return false;
	//	//}
	//	//
	//	//if ( opened )
	//	//{
	//	//	Open();
	//	//}
	//	//else
	//	//{
	//	//	Close();
	//	//}
	//	//
	//	// 
	//	//if (drawer_Handle)
	//	//{
	//	//   DrawerUp();	 
	//	//}
	//	//else
	//	//{
	//	//   DrawerDown();
	//	//}
	//
	//	//
	//	//return true;
	//}
	 

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

	}
	
	void SoundWeaponCaseOpenPlay()
	{
		 
		EffectSound sound =	SEffectManager.PlaySound( "weapon_case_open_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
		 
	}

	void SoundWeaponCaseClosePlay()
	{ 
		 
		EffectSound sound =	SEffectManager.PlaySound( "weapon_case_close_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
		 
	}
	 
	void SoundWeaponCaseDrawerUpPlay()
	{ 
		 
		EffectSound sound =	SEffectManager.PlaySound( "weapon_case_drawerup_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
		 
	}

	void SoundWeaponCaseDrawerDownPlay()
	{ 

		EffectSound sound =	SEffectManager.PlaySound( "weapon_case_drawerdown_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
		  
	}
	 
	void DetermineAction ( PlayerBase player )
	{
		Close();
	}		
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if (!super.CanPutInCargo(parent)) { return false; }
		if (GetNumberOfItems() == 0 && !IsOpen() && isDrawerUP())
		{
			return true;
		}
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
		 
		m_Drawer_Handle_Up = true; 
		//SoundSynchRemote();
		SoundSynchRemoteDrawer();

		UpdateVisualState();
		  
	}
	
	void DrawerDown()
	{ 

		m_Drawer_Handle_Up = false; 
		//SoundSynchRemote();
		SoundSynchRemoteDrawer();

		UpdateVisualState();
		 
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
		
		AddAction(ActionOpenWCase);
		AddAction(ActionCloseWCase); 	
		AddAction(ActionDrawerUp);		
		AddAction(ActionDrawerDown);	
		AddAction(ActionTakeItemToHands);	
	}

};
