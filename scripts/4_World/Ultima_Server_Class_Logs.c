// файл создается тут C:\Users\Алексей\AppData\Local\DayZ
class Ultima_Server_Class_Logs
{
	private FileHandle fhandle;
	void Ultima_Server_Class_Logs()
	{
	}
	void ~Ultima_Server_Class_Logs()
	{
	}
	void SaveLog(string fName, string fLine)
	{
		if (!FileExist(fName))
		{
			fhandle = OpenFile(fName, FileMode.WRITE);
		}
		else
		{
			fhandle = OpenFile(fName, FileMode.APPEND);
		}
		if (fhandle == 0)
		{
			Print("[#Ultima]: [Журналы]: Не удалось открыть файл для записи: " + fName);
			Print("[#Ultima]: [Журналы]: [Запись]: " + fLine);
			return;
		}
		FPrintln(fhandle, fLine);
		CloseFile(fhandle);
	}
}