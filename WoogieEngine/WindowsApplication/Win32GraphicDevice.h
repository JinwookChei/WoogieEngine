#pragma once


class Win32GraphicDevice : public IGraphicDevice
{
public:
	Win32GraphicDevice();
	~Win32GraphicDevice();

private:
	Win32Image* backBuffer_;
	Win32Image* mainBuffer_;
};