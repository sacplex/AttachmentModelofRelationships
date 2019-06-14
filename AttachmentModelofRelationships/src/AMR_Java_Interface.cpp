#include "AMR_Java_Interface.h"
#include "Knowledge.h"
#include "NPC.h"
#include <iostream> 
#include <stdio.h>
#include <unordered_map>
#include <Windows.h>

using namespace std;

NPC *npc;

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_print
(JNIEnv *, jobject)
{
	printf("Welcome to the Attachment Model of Relationships\n");
	cout << "Welcome to the Attachment Model of Relationships\n" << endl;

	Knowledge *knowledge = new Knowledge();
	knowledge->SetFact((char*)"teacher");

	printf(knowledge->GetFact()->GetFactData());
	printf("\n");
	fflush(stdout);

	delete knowledge;
}

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_start
(JNIEnv *, jobject)
{
	npc = new NPC();
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

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_finish
(JNIEnv *, jobject)
{
	delete npc;
}
