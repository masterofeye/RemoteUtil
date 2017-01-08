#include "ElementConfiguration.h"
#include "ElementConfiguration_p.h"
#include "ElementType.h"
#include "qdebug.h"

namespace RW{
	namespace SQL{

		ElementConfigurationPrivate::ElementConfigurationPrivate(ElementConfiguration* Parent) :
			//QObject(Parent),
			q_ptr(Parent),
			m_DisplayName(""),
			m_Function(""),
			m_GroupName(""),
			m_Type(nullptr),
			m_Name(""),
			m_ToolTip(""),
			m_RemoteWorkstationID(0)
		{
		}

		ElementConfigurationPrivate::~ElementConfigurationPrivate()
		{
		}


		ElementConfiguration::ElementConfiguration(QObject *Parent) : Entity(Parent),
			d_ptr(new ElementConfigurationPrivate(this))
		{
		}

		ElementConfiguration::~ElementConfiguration()
		{
		}

		ElementConfiguration::ElementConfiguration(const ElementConfiguration& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
		}

		ElementConfiguration& ElementConfiguration::operator=(ElementConfiguration& other)
		{
			std::swap(d_ptr, const_cast<ElementConfigurationPrivate*>(other.d_ptr));
			d_ptr->setParent(this);
			return *this;
		}


		ElementConfiguration::ElementConfiguration(ElementConfiguration&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
			
		}
		ElementConfiguration& ElementConfiguration::operator=(ElementConfiguration&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}


		ElementType* ElementConfiguration::Type() const
		{
			Q_D(const ElementConfiguration);
			return d->m_Type;
		}
		void ElementConfiguration::SetType(ElementType *Type)
		{
			Q_D(ElementConfiguration);
			d->m_Type = Type;
			emit TypeChanged();
		}

		QString ElementConfiguration::DisplayName() const
		{ 
			Q_D(const ElementConfiguration);
			return d->m_DisplayName;
		}

		void ElementConfiguration::SetDisplayName(QString DisplayName)
		{ 
			Q_D(ElementConfiguration);
			d->m_DisplayName = DisplayName;
			emit DisplayNameChanged();
		}

		QString ElementConfiguration::Name() const
		{
			Q_D(const ElementConfiguration);
			return d->m_Name;
		}

		void ElementConfiguration::SetName(QString Name)
		{ 
			Q_D(ElementConfiguration);
			d->m_Name = Name;
			emit NameChanged();
		}

		QString ElementConfiguration::GroupName() const
		{
			Q_D(const ElementConfiguration);
			return d_ptr->m_GroupName;
		}
		void ElementConfiguration::SetGroupName(QString GroupName)
		{
			Q_D(ElementConfiguration);
			d->m_GroupName = GroupName;
			emit GroupNameChanged();
		}

		QString ElementConfiguration::Function() const
		{
			Q_D(const ElementConfiguration);
			return d->m_Function;
		}

		void ElementConfiguration::SetFunction(QString Function)
		{ 
			Q_D(ElementConfiguration);
			d->m_Function = Function;
			emit FunctionChanged();
		}

		QString ElementConfiguration::ToolTip() const
		{	
			Q_D(const ElementConfiguration);
			return d->m_ToolTip;
		}

		void ElementConfiguration::SetToolTip(QString ToolTip)
		{
			Q_D(ElementConfiguration);
			d->m_ToolTip = ToolTip;
			emit ToolTipChanged();
		}

		quint64 ElementConfiguration::RemoteWorkstationID() const
		{
			Q_D(const ElementConfiguration);
			return d->m_RemoteWorkstationID;
		}

		void ElementConfiguration::SetRemoteWorkstationID(quint64 RemoteWorkstationID)
		{
			Q_D(ElementConfiguration);
			d->m_RemoteWorkstationID = RemoteWorkstationID;
			emit ToolTipChanged();
		}
		
	}
}
