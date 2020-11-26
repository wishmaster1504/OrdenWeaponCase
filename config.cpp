class CfgPatches
{
	class OrdenWeaponCase // Addon
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class OrdenWeaponCase // Addon
	{
		dir="OrdenWeaponCase";
		picture="";
		action="";
		hideName=0;
		hidePicture=1;
		name="OrdenWeaponCase";
		credits="ORDEN";
		author="ORDEN";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"OrdenWeaponCase\Scripts\4_World"
				};
			};
		};
	};
};
