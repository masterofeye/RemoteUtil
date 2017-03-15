#pragma once
#include "Entity.h"


namespace RW{
	namespace SQL{
		class ElementType;
		class ElementConfigurationPrivate;

		/*
		@brief Enititätsklasse, die die Konfiguration einer funktionieralität kapselt. Des kann z.b. die Kl30 sein oder aber 
		auch der FHostSP start. 
		*/
		class REMOTE_DATA_CONNECT_API ElementConfiguration :
			public Entity
		{
			Q_OBJECT
			Q_PROPERTY(ElementType* Type READ Type WRITE SetType NOTIFY TypeChanged)
			Q_PROPERTY(QString DisplayName  READ DisplayName WRITE SetDisplayName NOTIFY DisplayNameChanged)
			Q_PROPERTY(QString Name READ Name WRITE SetName NOTIFY NameChanged)
			Q_PROPERTY(QString GroupName READ GroupName WRITE SetGroupName NOTIFY GroupNameChanged)
			Q_PROPERTY(QString Function READ Function WRITE SetFunction NOTIFY FunctionChanged)
			Q_PROPERTY(QString ToolTip READ ToolTip WRITE SetToolTip NOTIFY ToolTipChanged)
			Q_PROPERTY(quint8 Pin READ Pin WRITE SetPin NOTIFY PinChanged)
			Q_PROPERTY(bool IsFeature READ IsFeature WRITE SetIsFeature NOTIFY IsFeatureChanged)
			Q_PROPERTY(bool RemoteViewRelevant READ RemoteViewRelevant WRITE SetRemoteViewRelevant NOTIFY RemoteViewRelevantChanged)
			Q_CLASSINFO("Version", "0.0.1")
		private:
			ElementConfigurationPrivate* d_ptr;
			Q_DECLARE_PRIVATE(ElementConfiguration);

		public:
			explicit ElementConfiguration(QObject *Parent = nullptr);
			~ElementConfiguration();

			/*
            @autor Ivo Kunadt
			@brief Copy Konstruktor
			@param [in]  Other
			*/
			ElementConfiguration(const ElementConfiguration& other);

			/*
            @autor Ivo Kunadt
			@brief Copy Operator
			@param [in] Other
			@return ElementConfiguration
			*/
			ElementConfiguration& ElementConfiguration::operator=(ElementConfiguration& other);

			/*
            @autor Ivo Kunadt
			@brief Move Konstruktor
			@param [in] Other
			*/
			ElementConfiguration(ElementConfiguration&& other);

			/*
            @autor Ivo Kunadt
			@brief Move Operator 
			@param Other 
			@return ElementConfiguration
			*/
			ElementConfiguration& ElementConfiguration::operator=(ElementConfiguration&& other);

			/*
            @autor Ivo Kunadt
			@brief Gibt den Type des Konfigurationselementes zurück
			*/
			ElementType* Type() const;

			/*
			@brief Setzt den Type des Konfigurationselement.
			@param [in] ElementType 
			*/
			void SetType(ElementType *Type);

			/*
            @autor Ivo Kunadt
			@brief Entspricht dem anzeigten Namen in der RemoteApp
			@return QStríng Der Name der Anzeigt wird für die Funktionalität in der RemoteApp
			*/
			QString DisplayName() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den Anzeigename für die RemoteApp
			@param [in] DisplayName 
			*/
			void SetDisplayName(QString DisplayName);

			/*
            @autor Ivo Kunadt
			@brief Name der Funktionalität. Kann intern genutzt werden um bestimmte Ereignisse zu triggern.
			@return QString Gibt den Namen der Funktionaliät zurück. 
			*/
			QString Name() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den Namen der Funktionalität.
			@param [in] Name Name der Funktionalität.
			*/
			void SetName(QString Name);

			/*
            @autor Ivo Kunadt
			@brief Name der Gruppe unter der die Funktionalität gelistet werden soll.
			@oaram GroupName Name der Gruppe
			*/
			QString GroupName() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den Gruppennamen in der die Funktionalität in der RemoteAPP gelistet werden soll.
			@param [in] GroupName Name der Gruppe.
			*/
			void SetGroupName(QString GroupName);

			/*
            @autor Ivo Kunadt
			@brief Funktion die hinter der Funktionalität steckt.
			@return QString
			*/
			QString Function() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt die Funkktion die hinter der Funtinionalität steckt.
			@param Function 
			*/
			void SetFunction(QString Function);

			/*
            @autor Ivo Kunadt
			@brief ToolTip die hinter der Funktionalität steckt.
			@return QString
			*/
			QString ToolTip() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den ToolTip die hinter der Funtinionalität steckt.
			@param ToolTip
			*/
			void SetToolTip(QString ToolTip);

			/*
            @autor Ivo Kunadt
			@brief RemoteWorkstationID die hinter der Funktionalität steckt.
			@return QString
			*/
			quint64 RemoteWorkstationID() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den RemoteWorkstationID die hinter der Funtinionalität steckt.
			@param ToolTip
			*/
			void SetRemoteWorkstationID(quint64 RemoteWorkstationID);

			/*
            @autor Ivo Kunadt
			@brief Zeigt an ob die Funktioninalität auf für die RemoteView wichtig ist und auch dort angezeigt werden muss.
			@return bool
			*/
			bool RemoteViewRelevant() const;

			/*
            @autor Ivo Kunadt
			@brief
			@param ToolTip
			*/
			void SetRemoteViewRelevant(bool RemoteViewRelevant);

			/*
            @autor Ivo Kunadt
			@brief 
			@return bool
			*/
			bool IsFeature() const;

			/*
            @autor Ivo Kunadt
			@brief
			@param 
			*/
			void SetIsFeature(bool Feature);

			/*
            @autor Ivo Kunadt
			@brief
			@return bool
			*/
			quint8 Pin() const;

			/*
            @autor Ivo Kunadt
			@brief
			@param
			*/
			void SetPin(quint8 Pin);

		signals:
			/*
            @autor Ivo Kunadt
			@brief Signalisiert wenn sich der Type geändert hat.
			*/
			void TypeChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich der Displayname geändert hat. 
			*/
			void DisplayNameChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich der Name geändert hat. 
			*/
			void NameChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich der Gruppenname geändert hat.
			*/
			void GroupNameChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich die Funktion geändert hat.
			*/
			void FunctionChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich der ToolTip geändert hat.
			*/
			void ToolTipChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich der RemoteWorkstationID geändert hat.
			*/
			void RemoteWorkstationIDChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich der RemoteViewRelevant geändert hat.
			*/
			void RemoteViewRelevantChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich IsFeature geändert hat.
			*/
			void IsFeatureChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgelöst wenn sich Pin geändert hat.
			*/
			void PinChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::ElementConfiguration)