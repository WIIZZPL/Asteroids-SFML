#pragma once
class App {
private:
	static App* instance;
	App();
	~App();
	App(App const& app) = delete;
	App const& operator=(App const& app) = delete;
	App(App&& app) = delete;
	App const& operator=(App&& app) = delete;


public:
	static App* getInstance();

};