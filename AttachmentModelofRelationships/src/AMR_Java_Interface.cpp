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

JNIEXPORT void JNICALL Java_portal_NPCNativePortal_finish
(JNIEnv *, jobject)
{
	delete npc;
}
