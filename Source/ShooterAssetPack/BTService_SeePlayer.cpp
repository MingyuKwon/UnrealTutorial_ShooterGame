// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SeePlayer.h"
#include "AIController.h"
#include "kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTService_SeePlayer::UBTService_SeePlayer()
{
	NodeName = TEXT("Can see Player");
}

void UBTService_SeePlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* playerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	if (!playerCharacter) return;

	if (OwnerComp.GetAIOwner()->LineOfSightTo(playerCharacter))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), playerCharacter->GetActorLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}

}
