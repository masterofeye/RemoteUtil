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
			@brief Gibt den Type des Konfigurationselementes zur�ck
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
			@return QStr�ng Der Name der Anzeigt wird f�r die Funktionalit�t in der RemoteApp
			*/
			QString DisplayName() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den Anzeigename f�r die RemoteApp
			@param [in] DisplayName 
			*/
			void SetDisplayName(QString DisplayName);

			/*
            @autor Ivo Kunadt
			@brief Name der Funktionalit�t. Kann intern genutzt werden um bestimmte Ereignisse zu triggern.
			@return QString Gibt den Namen der Funktionali�t zur�ck. 
			*/
			QString Name() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den Namen der Funktionalit�t.
			@param [in] Name Name der Funktionalit�t.
			*/
			void SetName(QString Name);

			/*
            @autor Ivo Kunadt
			@brief Name der Gruppe unter der die Funktionalit�t gelistet werden soll.
			@oaram GroupName Name der Gruppe
			*/
			QString GroupName() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den Gruppennamen in der die Funktionalit�t in der RemoteAPP gelistet werden soll.
			@param [in] GroupName Name der Gruppe.
			*/
			void SetGroupName(QString GroupName);

			/*
            @autor Ivo Kunadt
			@brief Funktion die hinter der Funktionalit�t steckt.
			@return QString
			*/
			QString Function() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt die Funkktion die hinter der Funtinionalit�t steckt.
			@param Function 
			*/
			void SetFunction(QString Function);

			/*
            @autor Ivo Kunadt
			@brief ToolTip die hinter der Funktionalit�t steckt.
			@return QString
			*/
			QString ToolTip() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den ToolTip die hinter der Funtinionalit�t steckt.
			@param ToolTip
			*/
			void SetToolTip(QString ToolTip);

			/*
            @autor Ivo Kunadt
			@brief RemoteWorkstationID die hinter der Funktionalit�t steckt.
			@return QString
			*/
			quint64 RemoteWorkstationID() const;

			/*
            @autor Ivo Kunadt
			@brief Setzt den RemoteWorkstationID die hinter der Funtinionalit�t steckt.
			@param ToolTip
			*/
			void SetRemoteWorkstationID(quint64 RemoteWorkstationID);

			/*
            @autor Ivo Kunadt
			@brief Zeigt an ob die Funktioninalit�t auf f�r die RemoteView wichtig ist und auch dort angezeigt werden muss.
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
			@brief Signalisiert wenn sich der Type ge�ndert hat.
			*/
			void TypeChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich der Displayname ge�ndert hat. 
			*/
			void DisplayNameChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich der Name ge�ndert hat. 
			*/
			void NameChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich der Gruppenname ge�ndert hat.
			*/
			void GroupNameChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich die Funktion ge�ndert hat.
			*/
			void FunctionChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich der ToolTip ge�ndert hat.
			*/
			void ToolTipChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich der RemoteWorkstationID ge�ndert hat.
			*/
			void RemoteWorkstationIDChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich der RemoteViewRelevant ge�ndert hat.
			*/
			void RemoteViewRelevantChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich IsFeature ge�ndert hat.
			*/
			void IsFeatureChanged();

			/*
            @autor Ivo Kunadt
			@brief Wird ausgel�st wenn sich Pin ge�ndert hat.
			*/
			void PinChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::ElementConfiguration)