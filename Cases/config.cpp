class CfgPatches
{
	class Orden_Weapon_Case
	{
		units[] = {"Orden_Weapon_Case"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Containers"};
	};
};
class CfgSlots
{
	class Slot_Weapon1
	{
		name = "Weapon1";
		displayName = "Weapon1";
		//selection="Ammocan_1";		
		ghostIcon = "cat_common_cargo";
	};
	class Slot_Weapon2
	{
		name = "Weapon2";
		displayName = "Weapon2";
		//selection="Ammocan.002";		
	};
	class Slot_Weapon3
	{
		name = "Weapon3";
		displayName = "Weapon3";
		//selection="Ammocan003";		
	};
	class Slot_Weapon4
	{
		name = "Weapon4";
		displayName = "Weapon4";
		//selection="Ammocan003";		
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
		
		attachments[] = { "Weapon1", "Weapon2", "Weapon3", "Weapon4" };
		class GUIInventoryAttachmentsProps {
			class Rifle1
			{
				name = "Оружие1";
				description = "";
				attachmentSlots[] =
				{
					"Weapon1"	
				};
				icon = "shoulderleft";
			};
			class Rifle2
			{
				name = "Оружие2";
				description = "";
				attachmentSlots[] =
				{
					"Weapon2"
				};
				icon = "shoulderleft";
			};
			class Rifle3
			{
				name = "Оружие3";
				description = "";
				attachmentSlots[] =
				{
					"Weapon1"
				};
				icon = "shoulderleft";
			};
			class Rifle4
			{
				name = "Оружие4";
				description = "";
				attachmentSlots[] =
				{
					"Weapon1"
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
	class Proxyweapon1 : ProxyPart
	{
		model = "OrdenItems\Items\Ammobox\weaponProxy.p3d";
		scope = 2;
		inventorySlot[] =
		{
			"Weapon1"
		};
	};
	class Proxyweapon2 : ProxyPart
	{
		model = "OrdenItems\Items\Ammobox\weaponProxy.p3d";
		scope = 2;
		inventorySlot[] =
		{
			"Weapon2"
		};
	};
	class Proxyweapon3 : ProxyPart
	{
		model = "OrdenItems\Items\Ammobox\weaponProxy.p3d";
		scope = 2;
		inventorySlot[] =
		{
			"Weapon3"
		};
	};
	class Proxyweapon4 : ProxyPart
	{
		model = "OrdenItems\Items\Ammobox\weaponProxy.p3d";
		scope = 2;
		inventorySlot[] =
		{
			"Weapon4"
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