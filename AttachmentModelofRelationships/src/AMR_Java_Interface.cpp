#include <iostream> 
#include <stdio.h>
#include <unordered_map>
#include <Windows.h>

#include "AMR_Java_Interface.h"
#include "AMR/Knowledge.h"
#include "AMR/NPC.h"

AMR::NPC *npc;

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_test
(JNIEnv *, jobject)
{
	printf("NPC DLL TEST PRINT\n");

	fflush(stdout);
}

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_print
(JNIEnv *, jobject)
{
	printf("Welcome to the Attachment Model of Relationships\n");
	std::cout << "Welcome to the Attachment Model of Relationships\n" << std::endl;

	AMR::Knowledge *knowledge = new AMR::Knowledge();
	knowledge->SetFact("role", "teacher");

	printf(knowledge->GetFact("role")->GetFactData().c_str());
	printf("\n");
	fflush(stdout);

	delete knowledge;
}

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_start
(JNIEnv *, jobject)
{
	npc = new AMR::NPC();
	npc->PrintName();

	fflush(stdout);
}

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_addPlayer
(JNIEnv * env, jobject, jstring playerName)
{
	const char* name = env->GetStringUTFChars(playerName, NULL);
	
	npc->InsertPlayer(name);

	env->ReleaseStringUTFChars(playerName, name);
}

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_findPlayer
(JNIEnv * env, jobject, jstring playerName)
{
	const char* name = env->GetStringUTFChars(playerName, NULL);

	npc->FindPlayer(name);

	env->ReleaseStringUTFChars(playerName, name);
}

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_initPlayer
(JNIEnv * env, jobject, jstring _gameName, jstring _playerName)
{
	const char* gameName = env->GetStringUTFChars(_gameName, NULL);
	const char* playerName = env->GetStringUTFChars(_playerName, NULL);

	npc->FindPlayer(playerName);
	npc->CreateOrLoadGameFile(gameName, playerName);

	env->ReleaseStringUTFChars(_playerName, playerName);
	env->ReleaseStringUTFChars(_gameName, gameName);
}

JNIEXPORT jstring JNICALL Java_portal_NPCNativePortal_returnGreeting
(JNIEnv * env, jobject, jstring playerName)
{
	const char* name = env->GetStringUTFChars(playerName, NULL);

	const char* greeting = npc->GetGreeting(name);

	printf("%s", "Greeting: ");
	printf("%s\n", greeting);

	fflush(stdout);

	env->ReleaseStringUTFChars(playerName, name);

	return (*env).NewStringUTF(greeting);
}

JNIEXPORT jstring JNICALL Java_portal_NPCNativePortal_returnName
(JNIEnv * env, jobject)
{
	const char* name = npc->GetName();
	
	return (*env).NewStringUTF(name);
}

JNIEXPORT jstring JNICALL Java_portal_NPCNativePortal_returnAge
(JNIEnv * env, jobject)
{
	const char* age = npc->GetAge();

	return (*env).NewStringUTF(age);
}

JNIEXPORT jstring JNICALL Java_portal_NPCNativePortal_returnStudy
(JNIEnv * env, jobject)
{
	const char* study = npc->GetStudy();

	return (*env).NewStringUTF(study);
}

JNIEXPORT jstring JNICALL Java_portal_NPCNativePortal_returnVersion
(JNIEnv * env, jobject)
{
	const char* version = npc->GetVersion();

	return (*env).NewStringUTF(version);
}

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_finish
(JNIEnv *, jobject)
{
	delete npc;
}
