#include "GeneralSettings.h"
#include "GeneralSettings_p.h"

namespace RW
{
	namespace SQL
	{
		GeneralSettingsPrivate::GeneralSettingsPrivate(GeneralSettings *Parent) :
			QObject(Parent),
			q_ptr(Parent)
		{
		}

		GeneralSettingsPrivate::~GeneralSettingsPrivate()
		{
		}



		GeneralSettings::GeneralSettings(QObject *Parent) : Entity(Parent),
			d_ptr(new GeneralSettingsPrivate(this))
		{
		}


		GeneralSettings::~GeneralSettings()
		{
		}

		GeneralSettings::GeneralSettings(const GeneralSettings& other) : d_ptr(const_cast<GeneralSettingsPrivate*>(other.d_ptr))
		{

		}

		GeneralSettings& GeneralSettings::operator=(GeneralSettings& other)
		{
			std::swap(d_ptr, const_cast<GeneralSettingsPrivate*>(other.d_ptr));
			d_ptr->setParent(this);
			return *this;
		}


		GeneralSettings::GeneralSettings(GeneralSettings&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
		}

		GeneralSettings& GeneralSettings::operator = (GeneralSettings&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}
	}
}