#include "DataManager.h"

#define LOAD_TABLE(tablePtr, tableClass, tableFile, callback, count) \
	{\
	std::string jsonpath = FileUtils::getInstance()->fullPathForFilename(tableFile);\
	data = FileUtils::getInstance()->getDataFromFile(jsonpath);\
	tablePtr = new tableClass(data.getBytes(), (int)data.getSize());\
	count++;\
	if(callback != nullptr)\
	callback(count);\
	}

static DataManager* _instance = nullptr;

DataManager::DataManager(void)
{
}


DataManager::~DataManager(void)
{

}

DataManager* DataManager::getInstance()
{
	if(_instance == nullptr)
	{
		_instance = new DataManager();
	}
	return _instance;
}

void DataManager::loadTable(const loadCallback& callback, std::string localConfig)
{
	int count = 0;
	Data data;
		LOAD_TABLE(m_Config, tables::Config, localConfig + "/" + tables::Config::fileName(), callback, count);
	LOAD_TABLE(m_Elf, tables::Elf, localConfig + "/" + tables::Elf::fileName(), callback, count);
	LOAD_TABLE(m_Language, tables::Language, localConfig + "/" + tables::Language::fileName(), callback, count);
	LOAD_TABLE(m_Monster, tables::Monster, localConfig + "/" + tables::Monster::fileName(), callback, count);
	LOAD_TABLE(m_Object, tables::Object, localConfig + "/" + tables::Object::fileName(), callback, count);
	LOAD_TABLE(m_Role, tables::Role, localConfig + "/" + tables::Role::fileName(), callback, count);
	LOAD_TABLE(m_Stage, tables::Stage, localConfig + "/" + tables::Stage::fileName(), callback, count);

}

