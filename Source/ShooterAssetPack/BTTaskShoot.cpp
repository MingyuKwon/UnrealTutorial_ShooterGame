// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskShoot.h"
#include "AIController.h"
#include "ShooterPlayer.h"

UBTTaskShoot::UBTTaskShoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTaskShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner())
	{
		AShooterPlayer* playerCharacter = Cast<AShooterPlayer>(OwnerComp.GetAIOwner()->GetPawn());
		
		if (playerCharacter)
		{
			playerCharacter->PullTrigger();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}