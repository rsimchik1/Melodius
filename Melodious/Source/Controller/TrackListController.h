#pragma once

#include "Observer.h"
#include "TrackController.h"
#include "../View/TrackControlsListView.h"
#include "../Model/ChannelMixer.h"
#include "../Utils/FileManager.h"
#include "../View/ArrangementView.h"

class ArrangementView;

class TrackListController : public Observer<TrackControlsListView>
{
public:
	static FileManager fileManager;
	TrackListController(ChannelMixer *mixer, ArrangementView *arrangementView, double sampleRate = 44100.0);
	void notify(TrackControlsListView *caller) override;
	void setSampleRate(double sampleRate);
private:
	std::shared_ptr<ChannelMixer> mixer;
	std::vector<std::shared_ptr<TrackController>> trackControllers;
	std::shared_ptr<ArrangementView> arrangementView;
	juce::AudioFormatManager formatManager;
	double sampleRate;
};
