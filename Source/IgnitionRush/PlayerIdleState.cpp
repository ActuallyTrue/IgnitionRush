// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIdleState.h"


PlayerIdleState::~PlayerIdleState()
{
}

void PlayerIdleState::Init(PlayerStateInput& stateInput) {

}

void PlayerIdleState::Enter(PlayerStateInput& stateInput) {
	UE_LOG(LogTemp, Warning, TEXT("Entering Idle State!!!!"));
}

void PlayerIdleState::Exit(PlayerStateInput& stateInput) {
	UE_LOG(LogTemp, Warning, TEXT("Exiting Idle State!!!!"));
	
}

void PlayerIdleState::Tick(PlayerStateInput& stateInput) {
	UE_LOG(LogTemp, Warning, TEXT("In Idle State!!!!"));
}

void PlayerIdleState::PhysicsTick(float SubstepDeltaTime, PlayerStateInput& stateInput) {

}
