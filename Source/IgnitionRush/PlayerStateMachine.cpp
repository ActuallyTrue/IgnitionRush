// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateMachine.h"
#include "PlayerIdleState.h"

// Sets default values for this component's properties
UPlayerStateMachine::UPlayerStateMachine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	OnCalculateCustomPhysics.BindUObject(this, &UPlayerStateMachine::CustomPhysics);
	UPlayerStateMachine::InitStateMap();
	// ...
}


// Called when the game starts
void UPlayerStateMachine::BeginPlay()
{
	Super::BeginPlay();
	UPlayerStateMachine::SetInitialState();

	// ...
	
}

void UPlayerStateMachine::InitStateMap()
{
	stateMap.Add(FString("PlayerIdleState"), new PlayerIdleState(*this));

}

void UPlayerStateMachine::SetInitialState()
{
	UPlayerStateMachine::ChangeState(FString("PlayerIdleState"));
}

void UPlayerStateMachine::ChangeState(FString stateName)
{
	currentState = stateMap[stateName];
	stateChanged = true;
}

// Called when the game ends
void UPlayerStateMachine::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// ...

}


// Called every frame
void UPlayerStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (stateChanged) {
		stateChanged = false;
		currentState->Enter(*stateInput);
	}
	currentState->Tick(*stateInput);
}

void UPlayerStateMachine::CustomPhysics(float DeltaTime, FBodyInstance* BodyInstance) {
	PhysicsTick(DeltaTime);
}

void UPlayerStateMachine::PhysicsTick_Implementation(float SubstepDeltaTime) {
	//physics code goes here...
	currentState->PhysicsTick(SubstepDeltaTime, *stateInput);
}


