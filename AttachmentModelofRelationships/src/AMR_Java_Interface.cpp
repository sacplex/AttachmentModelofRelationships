#include "AMR_Java_Interface.h"
#include "Knowledge.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_com_amr_cp_App_print
(JNIEnv *, jobject)
{
	printf("Welcome to the Attachment Model of Relationships\n");

	Knowledge *knowledge = new Knowledge();
	knowledge->SetFact((char*)"teacher");

	printf(knowledge->GetFact()->GetFactData());

	delete knowledge;
}
