modded class ActionConstructor
{	
	override void RegisterActions(TTypenameArray actions){
		super.RegisterActions(actions);
		actions.Insert(ActionCloseWCase);
		actions.Insert(ActionOpenWCase);	
		actions.Insert(ActionDrawerUp);	
		actions.Insert(ActionDrawerDown);	
	}
};