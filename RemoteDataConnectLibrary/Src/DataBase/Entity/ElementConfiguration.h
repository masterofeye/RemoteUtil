#pragma once
#include "Entity.h"


namespace RW{
	namespace SQL{
		class ElementType;
		class ElementConfigurationPrivate;

		/*
		@brief Enitit�tsklasse, die die Konfiguration einer funktionieralit�t kapselt. Des kann z.b. die Kl30 sein oder aber 
		auch der FHostSP start. 
		*/
		class REMOTE_DATA_CONNECT_API ElementConfiguration :
			public Entity
		{
			Q_OBJECT
			Q_PROPERTY(ElementType* Type READ Type WRITE SetType NOTIFY TypeChanged)
			Q_PROPERTY(QString DisplayName  READ DisplayName WRITE SetDisplayName NOTIFY DisplayNameChanged)
			Q_PROPERTY(QString Name READ Name WRITE SetName NOTIFY NameChanged)
			Q_PROPERTY(QString groupName READ GroupName WRITE SetGroupName NOTIFY GroupNameChanged)
			Q_PROPERTY(QString Function READ Function WRITE SetFunction NOTIFY FunctionChanged)
			Q_PROPERTY(QString ToolTip READ ToolTip WRITE SetToolTip NOTIFY ToolTipChanged)
			Q_PROPERTY(bool RemoteViewRelevant READ RemoteViewRelevant WRITE SetRemoteViewRelevant NOTIFY RemoteViewRelevantChanged)
			Q_CLASSINFO("Version", "0.0.1")
		private:
			ElementConfigurationPrivate* d_ptr;
			Q_DECLARE_PRIVATE(ElementConfiguration);

		public:
			explicit ElementConfiguration(QObject *Parent = nullptr);
			~ElementConfiguration();

			/*
			@brief Copy Konstruktor
			@param [in]  Other
			*/
			ElementConfiguration(const ElementConfiguration& other);

			/*
			@brief Copy Operator
			@param [in] Other
			@return ElementConfiguration
			*/
			ElementConfiguration& ElementConfiguration::operator=(ElementConfiguration& other);

			/*
			@brief Move Konstruktor
			@param [in] Other
			*/
			ElementConfiguration(ElementConfiguration&& other);

			/*
			@brief Move Operator 
			@param Other 
			@return ElementConfiguration
			*/
			ElementConfiguration& ElementConfiguration::operator=(ElementConfiguration&& other);

			/*
			@brief Gibt den Type des Konfigurationselementes zur�ck
			*/
			ElementType* Type() const;

			/*
			@brief Setzt den Type des Konfigurationselement.
			@param [in] ElementType 
			*/
			void SetType(ElementType *Type);

			/*
			@brief Entspricht dem anzeigten Namen in der RemoteApp
			@return QStr�ng Der Name der Anzeigt wird f�r die Funktionalit�t in der RemoteApp
			*/
			QString DisplayName() const;

			/*
			@brief Setzt den Anzeigename f�r die RemoteApp
			@param [in] DisplayName 
			*/
			void SetDisplayName(QString DisplayName);

			/*
			@brief Name der Funktionalit�t. Kann intern genutzt werden um bestimmte Ereignisse zu triggern.
			@return QString Gibt den Namen der Funktionali�t zur�ck. 
			*/
			QString Name() const;

			/*
			@brief Setzt den Namen der Funktionalit�t.
			@param [in] Name Name der Funktionalit�t.
			*/
			void SetName(QString Name);

			/*
			@brief Name der Gruppe unter der die Funktionalit�t gelistet werden soll.
			@oaram GroupName Name der Gruppe
			*/
			QString GroupName() const;

			/*
			@brief Setzt den Gruppennamen in der die Funktionalit�t in der RemoteAPP gelistet werden soll.
			@param [in] GroupName Name der Gruppe.
			*/
			void SetGroupName(QString GroupName);

			/*
			@brief Funktion die hinter der Funktionalit�t steckt.
			@return QString
			*/
			QString Function() const;

			/*
			@brief Setzt die Funkktion die hinter der Funtinionalit�t steckt.
			@param Function 
			*/
			void SetFunction(QString Function);

			/*
			@brief ToolTip die hinter der Funktionalit�t steckt.
			@return QString
			*/
			QString ToolTip() const;

			/*
			@brief Setzt den ToolTip die hinter der Funtinionalit�t steckt.
			@param ToolTip
			*/
			void SetToolTip(QString ToolTip);

			/*
			@brief RemoteWorkstationID die hinter der Funktionalit�t steckt.
			@return QString
			*/
			quint64 RemoteWorkstationID() const;

			/*
			@brief Setzt den RemoteWorkstationID die hinter der Funtinionalit�t steckt.
			@param ToolTip
			*/
			void SetRemoteWorkstationID(quint64 RemoteWorkstationID);

			/*
			@brief Zeigt an ob die Funktioninalit�t auf f�r die RemoteView wichtig ist und auch dort angezeigt werden muss.
			@return bool
			*/
			bool RemoteViewRelevant() const;

			/*
			@brief
			@param ToolTip
			*/
			void SetRemoteViewRelevant(bool RemoteViewRelevant);


		signals:
			/*
			@brief Signalisiert wenn sich der Type ge�ndert hat.
			*/
			void TypeChanged();

			/*
			@brief Wird ausgel�st wenn sich der Displayname ge�ndert hat. 
			*/
			void DisplayNameChanged();

			/*
			@brief Wird ausgel�st wenn sich der Name ge�ndert hat. 
			*/
			void NameChanged();

			/*
			@brief Wird ausgel�st wenn sich der Gruppenname ge�ndert hat.
			*/
			void GroupNameChanged();

			/*
			@brief Wird ausgel�st wenn sich die Funktion ge�ndert hat.
			*/
			void FunctionChanged();

			/*
			@brief Wird ausgel�st wenn sich der ToolTip ge�ndert hat.
			*/
			void ToolTipChanged();

			/*
			@brief Wird ausgel�st wenn sich der RemoteWorkstationID ge�ndert hat.
			*/
			void RemoteWorkstationIDChanged();

			/*
			@brief Wird ausgel�st wenn sich der RemoteViewRelevant ge�ndert hat.
			*/
			void RemoteViewRelevantChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::ElementConfiguration)