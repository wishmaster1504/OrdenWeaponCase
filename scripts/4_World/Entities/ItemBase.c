modded class ItemBase extends InventoryItem
{
	//bool	m_IsSoundSynchRemote2;
	bool	m_IsSoundSynchRemoteDrawer; // Поднять/Опустить ручку

	void InitItemVariables()
	{

		m_VarTemperature = GetTemperatureInit();
		m_VarWet = GetWetInit();
		m_VarLiquidType = GetLiquidTypeInit();
		m_VarQuantity = GetQuantityInit();//should be by the CE, this is just a precaution
		m_IsBeingPlaced = false;
		m_IsHologram = false;
		m_IsPlaceSound = false;
		m_IsDeploySound = false;
		m_IsTakeable = true;
		m_IsSoundSynchRemote = false;
		m_IsSoundSynchRemoteDrawer = false;
		m_CanBeMovedOverride = false;
		m_HeatIsolation = GetHeatIsolationInit();
		m_ItemModelLength = GetItemModelLength();

		//Define if item can be split and set ability to be combined accordingly
		if (ConfigGetBool("canBeSplit"))
			can_this_be_combined = ConfigGetBool("canBeSplit");

		if (ConfigIsExisting("itemBehaviour"))
		{
			m_ItemBehaviour = ConfigGetInt("itemBehaviour");
		}

		//RegisterNetSyncVariableInt("m_VariablesMask");
		if (HasQuantity()) RegisterNetSyncVariableFloat("m_VarQuantity", GetQuantityMin(), ConfigGetInt("varQuantityMax"));
		RegisterNetSyncVariableFloat("m_VarTemperature", GetTemperatureMin(), GetTemperatureMax());
		RegisterNetSyncVariableFloat("m_VarWet", GetWetMin(), GetWetMax(), 2);
		RegisterNetSyncVariableInt("m_VarLiquidType");

		RegisterNetSyncVariableInt("m_ColorComponentR", 0, 255);
		RegisterNetSyncVariableInt("m_ColorComponentG", 0, 255);
		RegisterNetSyncVariableInt("m_ColorComponentB", 0, 255);
		RegisterNetSyncVariableInt("m_ColorComponentA", 0, 255);

		RegisterNetSyncVariableBool("m_IsBeingPlaced");
		RegisterNetSyncVariableBool("m_IsTakeable");
		RegisterNetSyncVariableBool("m_IsHologram");

		
		

	};
	 
	 

	void SoundSynchRemoteResetDrawer()
	{
		 
		m_IsSoundSynchRemoteDrawer = false;
			  
		SetSynchDirty();
	}
	 

	void SoundSynchRemoteDrawer()
	{ 
		m_IsSoundSynchRemoteDrawer = true;

		SetSynchDirty();
	}
	 
	bool IsSoundSynchRemoteDrawer()
	{
		return m_IsSoundSynchRemoteDrawer;
	}

};