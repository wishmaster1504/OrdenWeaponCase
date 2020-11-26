modded class ActionConstructor
{	
	override void RegisterActions(TTypenameArray actions){
		super.RegisterActions(actions);
		actions.Insert(ActionCloseBox);
		actions.Insert(ActionOpenBox);	
		actions.Insert(ActionDrawerUp);	
		actions.Insert(ActionDrawerDown);	
	}
};