class CfgPatches
{
	class Orden_Weapon_Case
	{
		units[] = {"Orden_Weapon_Case"};
		weapons[] = {"Rifle_Base"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Containers","DZ_Weapons_Firearms"};
	};
};
class CfgSlots
{
	class Slot_weaponProxy
	{
		name = "weaponProxy";
		displayName = "weaponProxy";
		//selection="Ammocan_1";		
		ghostIcon = "cat_common_cargo";
	};
	class Slot_weaponProxy2
	{
		name = "weaponProxy2";
		displayName = "weaponProxy2";
		//selection="Ammocan.002";		
	};
	class Slot_weaponProxy3
	{
		name = "weaponProxy3";
		displayName = "weaponProxy3";
		//selection="Ammocan003";		
	};
	class Slot_weaponProxy4
	{
		name = "weaponProxy4";
		displayName = "weaponProxy4";
		//selection="Ammocan003";		
	};
};
class CfgWeapons
{
	class RifleCore;
	class Rifle_Base: RifleCore
	{
		inventorySlot[]=
		{
			"Shoulder",
			"Melee",
			"kuroakitaGUN1",
			"kuroakitaGUN2",
			"kuroakitaGUN3",
			"kuroakitaGUN4",
			"kuroakitaGUN5",
			"kuroakitaGUN6",
			"kuroakitaGUN7",
			"kuroakitaGUN8",
			"kuroakitaGUN9",
			"kuroakitaGUN10",
			"kuroakitaGUN11",
			"kuroakitaGUN12",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Shoulder4",
			"Shoulder5",
			"Shoulder6",
			"Shoulder7",
			"Shoulder8",
			"Shoulder9",
			"Shoulder10",
			"Shoulder11",
			"Shoulder12",
			"Shoulder13",
			"Shoulder14",
			"Shoulder15",
			"Shoulder16",
			"Shoulder17",
			"Shoulder18",
			"Shoulder19",
			"Shoulder20",
			"Shoulder21",
			"Shoulder22",
			"Shoulder23",
			"Shoulder24",
			"Shoulder25",
			"Shoulder26",
			"Shoulder27",
			"Shoulder28",
			"Shoulder29",
			"Shoulder30",
			"Shoulder111",
			"Shoulder112",
			"weaponProxy",
			"weaponProxy2",
			"weaponProxy3",
			"weaponProxy4"
		};
	};		
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class WorldContainer_Base;  
	
	class Orden_Weapon_Case: Container_Base
	{
		scope = 2;
		displayName = "Кейс для оружия";
		descriptionShort = "Кейс для оружия";
		model = "OrdenWeaponCase\Cases\WeaponCase.p3d";
		SingleUseActions[] = {527};
        InteractActions[] = {1025, 1026};
        ContinuousActions[] = {155};
        destroyOnEmpty = 0;
        varQuantityDestroyOnMin = 0;
        quantityBar = 0;
        varQuantityMax = 0;
        carveNavmesh = 1;
        canBeDigged = 0;
        heavyItem = 1;
        weight = 10000;
        itemSize[] = {1, 1};
        itemBehaviour = 0;
        physLayer = "item_large";
        allowOwnedCargoManipulation = 1;
        lootTag[] = {"Work"};
        storageCategory = 1;    
        class Cargo
        {
            itemsCargoSize[]={10,10};
            openable=0;
            allowOwnedCargoManipulation=1;
        };
        class AnimEvents {
            class SoundWeapon {
                class movement {
                    soundSet = "seachest_movement_SoundSet";
                    id = 1;
                };
                
                class pickUpItem_Light {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 796;
                };
                
                class pickUpItem {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 797;
                };
                
                class drop {
                    soundset = "seachest_drop_SoundSet";
                    id = 898;
                };
            };
        };   
		class AnimationSources
        {    
            class Door1
            {
                source="user";
                initPhase=1;
                animPeriod=1;
            };   
            class Drawer_Handle
            {
                source="user";
                initPhase=0;
                animPeriod=1;
            };   
			
			class Clap1
			{
			   source="user";
			   initPhase=0;
			   animPeriod=1;
			};	
			
			class Clap2
			{
			   source="user";
			   initPhase=0;
			   animPeriod=1;
			};	
			
			class Clap3
			{
			   source="user";
			   initPhase=0;
			   animPeriod=1;
			};	
			
			class Clap4
			{
			   source="user";
			   initPhase=0;
			   animPeriod=1;
			};	
        };	
		
		attachments[] = { "weaponProxy", "weaponProxy2", "weaponProxy3", "weaponProxy4" };
		class GUIInventoryAttachmentsProps {
			class Rifle1
			{
				name = "Оружие1";
				description = "";
				attachmentSlots[] =
				{
					"weaponProxy"	
				};
				icon = "shoulderleft";
			};
			class Rifle2
			{
				name = "Оружие2";
				description = "";
				attachmentSlots[] =
				{
					"weaponProxy2"
				};
				icon = "shoulderleft";
			};
			class Rifle3
			{
				name = "Оружие3";
				description = "";
				attachmentSlots[] =
				{
					"weaponProxy3"
				};
				icon = "shoulderleft";
			};
			class Rifle4
			{
				name = "Оружие4";
				description = "";
				attachmentSlots[] =
				{
					"weaponProxy4"
				};
				icon = "shoulderleft";
			};
			/*class Ammocans {
				name = "Кейсы";
				description = "";
				attachmentSlots[] = { "Ammocan","Ammocan3","Ammocan2" };
			};*/
		};
	};
	
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyVehiclePart : ProxyAttachment
	{
		scope = 2;
		simulation = "ProxyInventory";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 0;
	};
	class ProxyPart
	{
		scope = 2;
		simulation = "ProxyInventory";
		model = "";
		inventorySlot = "";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 1;
	};
	class ProxyweaponProxy : ProxyPart
	{
		model = "OrdenWeaponCase\Cases\weaponProxy.p3d";
		scope = 2;
		inventorySlot[] =
		{
			"weaponProxy"
		};
	};
	class ProxyweaponProxy2 : ProxyPart
	{
		model = "OrdenWeaponCase\Cases\weaponProxy2.p3d";
		scope = 2;
		inventorySlot[] =
		{
			"weaponProxy2"
		};
	};
	class ProxyweaponProxy3 : ProxyPart
	{
		model = "OrdenWeaponCase\Cases\weaponProxy3.p3d";
		scope = 2;
		inventorySlot[] =
		{
			"weaponProxy3"
		};
	};
	class ProxyweaponProxy4 : ProxyPart
	{
		model = "OrdenWeaponCase\Cases\weaponProxy4.p3d";
		scope = 2;
		inventorySlot[] =
		{
			"weaponProxy4"
		};
	};
	/*
	class Proxyammocan2 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"Ammocan2"
		};
		model = "OrdenItems\Items\Ammobox\ammocan2.p3d";
	};
	class Proxyammocan3 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"Ammocan3"
		};
		model = "OrdenItems\Items\Ammobox\ammocan3.p3d";
	};*/
};