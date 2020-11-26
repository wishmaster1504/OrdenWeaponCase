////////////////////////////////////////////////////////////////////
//DeRap: sounds_hpp\config.bin
//Produced from Wishmaster
// 
//'now' is   13/11/2020
// Last Mod: 13/11/2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

 

class CfgPatches
{
	class Weapon_Case_Sounds_Effects
	{
		units[] = {"Weapon_Case_Open","Weapon_Case_Close","Weapon_Case_DrawerUp","Weapon_Case_DrawerDown"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Vehicles_Wheeled"};
	};
};

class CfgSoundShaders
{
	 
	class baseWeaponCase_SoundShader
	{
		range = 50;
	};
	
	class weapon_case_open_SoundShader: baseWeaponCase_SoundShader
	{
		samples[] = {{"OrdenWeaponCase\Sounds\WeaponCase\door_open_scrip_1",1}};
		volume = 0.25;
	};
	
	class weapon_case_close_SoundShader: baseWeaponCase_SoundShader
	{
		samples[] = {{"OrdenWeaponCase\Sounds\WeaponCase\door_close_scrip_1",1}};
		volume = 0.25;
	};
	
	class weapon_case_drawerup_SoundShader: baseWeaponCase_SoundShader
	{
		samples[] = {{"OrdenWeaponCase\Sounds\WeaponCase\drawer_up_scrip",1}};
		volume = 0.25;
	};				
	
	class weapon_case_drawerdown_SoundShader: baseWeaponCase_SoundShader
	{
		samples[] = {{"OrdenWeaponCase\Sounds\WeaponCase\drawer_down_scrip",1}};
		volume = 0.25;
	};
	
};

class CfgSoundSets
{
	class baseWeaponCase_SoundSet
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	
	class weapon_case_open_SoundSet: baseWeaponCase_SoundSet
	{
		soundShaders[] = {"weapon_case_open_SoundShader"};
		frequencyRandomizer = 1;
		volumeRandomizer = 1;
	};
	
	class weapon_case_close_SoundSet: baseWeaponCase_SoundSet
	{
		soundShaders[] = {"weapon_case_close_SoundShader"};
		frequencyRandomizer = 1;
		volumeRandomizer = 1;
	};
	
	class weapon_case_drawerup_SoundSet: baseWeaponCase_SoundSet
	{
		soundShaders[] = {"weapon_case_drawerup_SoundShader"};
		frequencyRandomizer = 1;
		volumeRandomizer = 1;
	};
	
	class weapon_case_drawerdown_SoundSet: baseWeaponCase_SoundSet
	{
		soundShaders[] = {"weapon_case_drawerdown_SoundShader"};
		frequencyRandomizer = 1;
		volumeRandomizer = 1;
	};
	
};