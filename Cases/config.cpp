class CfgPatches
{
	class Orden_Weapon_Case
	{
		units[] = {"Orden_Weapon_Case"};
		weapons[] = {"Rifle_Base"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Containers","DZ_Weapons_Firearms","OrdenTemplates","DZ_Sounds_Weapons","DZ_Scripts" };
	};

	class Orden_Weapon_Case_MagOptGl
	{
		units[] = { "Orden_Weapon_Case_MagOptGl" };
		weapons[] = { "Rifle_Base", "Magazine_Base" };
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data","DZ_Gear_Containers","DZ_Weapons_Firearms","OrdenTemplates","DZ_Weapons_Magazines","DZ_Weapons_Optics" };
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
		ghostIcon = "cat_common_cargo";
	};
	class Slot_weaponProxy3
	{
		name = "weaponProxy3";
		displayName = "weaponProxy3";
		//selection="Ammocan003";		
		ghostIcon = "cat_common_cargo";
	};
	class Slot_weaponProxy4
	{
		name = "weaponProxy4";
		displayName = "weaponProxy4";
		//selection="Ammocan003";		
		ghostIcon = "cat_common_cargo";
	};


	class Slot_magProxy
	{
		name = "magProxy";
		displayName = "magProxy";
		selection="magProxy";		
		ghostIcon = "cat_common_cargo";
	};
	class Slot_magProxy2
	{
		name = "magProxy2";
		displayName = "magProxy2";
		//selection = "magProxy2";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_magProxy3
	{
		name = "magProxy3";
		displayName = "magProxy3";
		//selection = "magProxy3";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_magProxy4
	{
		name = "magProxy4";
		displayName = "magProxy4";
		//selection = "magProxy4";
		ghostIcon = "cat_common_cargo";
	};

	class Slot_optProxy1
	{
		name = "optProxy1";
		displayName = "optProxy1";
		//selection = "optProxy1";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_optProxy2
	{
		name = "optProxy2";
		displayName = "optProxy2";
		//selection = "optProxy2";
		ghostIcon = "cat_common_cargo";
	};

	class Slot_glProxy1
	{
		name = "glProxy1";
		displayName = "glProxy1";
		//selection = "glProxy1";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_glProxy2
	{
		name = "glProxy2";
		displayName = "glProxy2";
		//selection = "glProxy2";
		ghostIcon = "cat_common_cargo";
	};




};
class CfgWeapons
{
	class RifleCore;
	//class Rifle_Base_Template;
	class Rifle_Base: RifleCore
	//class Rifle_Base : Rifle_Base_Template{};
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

class CfgMagazines 
{
	class DefaultMagazine;
	class Magazine_Base;
	class Orden_Magazine_Base : Magazine_Base
	{
		inventorySlot[] = { "magProxy", "magProxy2", "magProxy3", "magProxy4" };
		cargoClass = "Magazine_Base"; // weaponOptics
	};
};

	

// OpticsInfoDefault
// class OpticsInfo: OpticsInfoDefault{};
// ItemOptics
// ItemSuppressor


class CfgVehicles
{

	//class AK_Suppressor;

	class Inventory_Base;
	class Container_Base;
	class WorldContainer_Base;  
	

	//class HuntingOptic; 
	class ItemOptics : Inventory_Base
	{
		inventorySlot[] = { "optProxy1", "optProxy2" };
		//cargoClass = "ItemOptics"; // OpticsInfoDefault   Mag_AK101_30Rnd   AK_Suppressor
		//cargoClass = "OpticsInfoDefault"; // HuntingOptic --> ItemOptics
		cargoClass = "Inventory_Base";
	};


	class ItemSuppressor : Inventory_Base
	{
		inventorySlot[] = { "glProxy1", "glProxy2" };
		cargoClass = "ItemSuppressor";
	};

	class Orden_Weapon_Case: Container_Base
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_Orden_Weapon_Case";
		descriptionShort = "$STR_cfgvehicles_Orden_Weapon_Case";
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
        weight = 5000;
        itemSize[] = {3, 8};
        itemBehaviour = 0;
        physLayer = "item_large";
        allowOwnedCargoManipulation = 1;
        lootTag[] = {"Work"};
        storageCategory = 1;    
        class Cargo
        {
            itemsCargoSize[]={10,5}; // 50 слотов
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

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100000000000;
				};
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
		
		};
	};
	


	class Orden_Weapon_Case_MagOptGl : Orden_Weapon_Case
	{
		displayName = "Кейс для оружия с магазинами";
		descriptionShort = "Кейс для оружия с магазинами";
		model = "OrdenWeaponCase\Cases\WeaponCaseMagOptGl.p3d";


		attachments[] = { "magProxy", "magProxy2", "magProxy3", "magProxy4", "optProxy1", "optProxy2", "glProxy1", "glProxy2","weaponProxy", "weaponProxy2" };
		class GUIInventoryAttachmentsProps {

			class Rifles
			{
				name = "Оружие";
				description = "";
				attachmentSlots[] =
				{
					//"weaponProxy3", "weaponProxy4"
					"weaponProxy", "weaponProxy2"
				};
				icon = "shoulderleft";
			};
			class Mags
			{
				name = "Магазины";
				description = "";
				attachmentSlots[] =
				{
					"magProxy", "magProxy2", "magProxy3", "magProxy4"
				};
				//icon = "shoulderleft";
			};

			class Optics
			{
				name = "Оптика";
				description = "";
				attachmentSlots[] =
				{
					"optProxy1", "optProxy2"
				};
				icon = "shoulderleft";
			};

			class Suppressor // глушитель
			{
				name = "Глушители";
				description = "";
				attachmentSlots[] =
				{
					"glProxy1", "glProxy2"
				};
				//icon = "shoulderleft";
			};

		};

	}; // Orden_Weapon_Case_MagOptGl


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
	// прокси для магазинов
	class ProxymagProxy : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"magProxy"
		};
		model = "OrdenWeaponCase\Cases\magProxy.p3d";
	};
	class ProxymagProxy2 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"magProxy2"
		};
		model = "OrdenWeaponCase\Cases\magProxy2.p3d";
	};
	class ProxymagProxy3 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"magProxy3"
		};
		model = "OrdenWeaponCase\Cases\magProxy3.p3d";
	};
	class ProxymagProxy4 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"magProxy4"
		};
		model = "OrdenWeaponCase\Cases\magProxy4.p3d";
	};

	// прокси для оптики
	class ProxyoptProxy1 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"optProxy1"
		};
		model = "OrdenWeaponCase\Cases\optProxy1.p3d";
	};
	class ProxyoptProxy2 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"optProxy2"
		};
		model = "OrdenWeaponCase\Cases\optProxy2.p3d";
	};
// прокси для глушителей
	class ProxyglProxy1 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"glProxy1"
		};
		model = "OrdenWeaponCase\Cases\glProxy1.p3d";
	};
	class ProxyglProxy2 : ProxyPart
	{
		scope = 2;
		inventorySlot[] =
		{
			"glProxy2"
		};
		model = "OrdenWeaponCase\Cases\glProxy2.p3d";
	};


};