#include "Event/EventManager.h"

Event* EventManager::ChooseEvent() {
	int pos = rand() % EnumClass::PROBABILITY;
	if (pos > EnumClass::BOUND)
		return nullptr;
	pos = rand() % 20;
	Event* event = nullptr;
	if (pos == 0 && CheckCave()) {
		event = saintWater->CreateEvent();
		CaveCount++;
	}
	else if (pos == 1 && CheckBush()) {
		event = bear->CreateEvent();
		BushCount++;
	}
	else if (2 <= pos && pos <= 3 && CheckCave() && CaveCount > 0) {
		event = teleport->CreateEvent();
		CaveCount++;
	}
	else if (4 <= pos && pos <= 5 && CheckBush()) {
		event = wolf->CreateEvent();
		BushCount++;
	}
	else if (6 <= pos && pos <= 8 && CheckBush()) {
		event = rabbit->CreateEvent();
		BushCount++;
	}
	else if (9 <= pos && pos <= 12 && CheckBush()) {
		event = berry->CreateEvent();
		BushCount++;
	}
	else if (12 <= pos && pos <= 14 && CheckCave()) {
		event = earthQuake->CreateEvent();
		CaveCount++;
	}
	else if (CheckCave()) {
		event = water->CreateEvent();
		CaveCount++;
	}
	if (event == nullptr)
		return event;
	Tracker[event] = EnumClass::LIFE_TIME;
	return event;
}

Event* EventManager::ChooseConcreteEvent(EnumClass::Events event) {
	Event* res = nullptr;
	if (event == EnumClass::SAINT_WATER) {
		res = saintWater->CreateEvent();
		CaveCount++;
	}
	if (event == EnumClass::WATER) {
		res = water->CreateEvent();
		CaveCount++;
	}
	if (event == EnumClass::BEAR) {
		res = bear->CreateEvent();
		BushCount++;
	}
	if (event == EnumClass::BERRY) {
		res = berry->CreateEvent();
		BushCount++;
	}
	if (event == EnumClass::WOLF) {
		res = wolf->CreateEvent();
		BushCount++;
	}
	if (event == EnumClass::RABBIT) {
		res = wolf->CreateEvent();
		BushCount++;
	}
	if (event == EnumClass::TELEPORT) {
		res = teleport->CreateEvent();
		CaveCount++;
	}
	if (event == EnumClass::EARTHQUAKE) {
		res = earthQuake->CreateEvent();
		CaveCount++;
	}
	Tracker[res] = EnumClass::LIFE_TIME;
	return res;
}

bool EventManager::UseEvent(Event* event) {
	if (!event->Happen())
		return false;
	mStatus = event->GetStatus();
	DeleteEvent(event);
	return true;
}

bool EventManager::CheckBush() {
	return BushCount <= mField->GetHeight() * mField->GetWidth() / 32;
}

bool EventManager::CheckCave() {
	return CaveCount <= mField->GetHeight() * mField->GetWidth() / 32;
}

bool EventManager::CheckEvent(Event* event) {
	if (--Tracker[event] == 0) {
		DeleteEvent(event);
		return true;
	}
	return false;
}

void EventManager::DeleteEvent(Event* event) {
	Tracker.erase(event);
	if (dynamic_cast<Bush*>(event) != nullptr)
		BushCount--;
	else if (dynamic_cast<Cave*>(event) != nullptr)
		CaveCount--;
	delete event;
}

EnumClass::Events EventManager::GetStatus() {
	EnumClass::Events cur = mStatus;
	mStatus = EnumClass::NONE;
	return cur;
}