#pragma once

#include <qobject.h>
#include <QMetaType>
namespace RW{
	namespace COM{
//#ifdef Q_MOC_RUN
//		class COM
//		{
//			Q_GADGET
//		public:
//#endif
			enum class MessageDescription
			{
				EX_CanEasyStartApplication,
				EX_CanEasyLoadWorkspace,
				EX_CanEasyCloseApplication,
				EX_CanEasyStartSimulation,
				EX_CanEasyStopSimulation,
				EX_MKSLogin,
				EX_MKSStartDownload,
				EX_MKSCreateSandBox,
				EX_MKSDropSandbox,
				EX_MKSClose,
				EX_FHostSPStartFHost,
				EX_FHostSPLoadFlashFile,
				EX_FHostSPCloseFHost,
				EX_FHostSPGetState,
				EX_FHostSPAbortSequence,
				EX_FHostSPCloseSequence,
				EX_FHostSPStartFlash,
				EX_FHostSPGetProgress,
				EX_PortalInfoFittingAC,
				EX_PortalInfoAcByIcom,
				EX_PortalInfoReleases,
				EX_PortalInfoSoftwareById,
				EX_PortalInfoShowDialog,
				EX_PortalInfoCloseDialog,
				EX_FileUtilUnZip,
				EX_FileUtilDelete,
				EX_UsbHidLoaderFlashFile,
				EX_PrintDebugInformation,
				IN_ToggleCl30Fast,
				IN_ToggleCl30Slow,
				EX_StartInactivityTimer,
				EX_StopInactivityTimer,
				IN_PowerSupply,
				IN_PowerStripe,
				Amount
			};


//#ifdef Q_MOC_RUN
//			Q_ENUM(MessageDescription)
//#endif

			enum class ErrorDecscription
			{
                Success,
                Error,
                Busy,
                ErrorCanEasyComServerMissing,
                ErrorCanEasyStartSimulation,
                ErrorCanEasySimulationIsRunningFailed,
                ErrorCanEasyStopSimulation,
                ErrorCanEasyWorkspaceNotFound,
                ErrorCanEasyWorkspaceNotLoaded,
                ErrorCanEasyApplicationError,
                ErrorCanEasyDeInitError,
                ErrorMKSLogin,
                ErrorMKSLocationMissing,
                ErrorMKSError,
                ErrorMKSSandBoxCreation,
                ErrorMKSSanbBoxDrop,
                ErrorMKSCloseFailed,
                ErrorMKSMissingParameter,
                ErrorFHostSPStartApplication,
                ErrorFHostSPSequenceStop,
                ErrorFHostSPSequenceStart,
                ErrorFHostSPLoadFlashfileStatusFailed,
                ErrorFHostSPLoadFlashfileFailed,
                ErrorFHostSPFlashfileNotExits,
                ErrorFHostSPGetProgress,
                ErrorFHostSPCloseApplication,
                ErrorFHostSPGetStateFailed,
                ErrorFHostSPAbortFailed,
                ErrorPortalInfoFinalRegexCheck,
                ErrorPortalInfoProjectnameCount,
                ErrorPortalInfoProjectCount,
                ErrorPortalInfoSamplePhaseAndReleaseCount,
                ErrorPortalInfoSamplePhaseCount,
                ErrorPortalInfoPrepareReleaseInformation,
                ErrorPortalInfoReleaseCount,
                ErrorFileUtilMissingZipFile,
                ErrorFileUtilNoSevenZip,
                ErrorFileUtilFailed,
                ErrorFileUtilDirectoryDontExists,
                ErrorFileUtilDeleteFailed,
                ErrorFileUsbHidLoaderFileDontExists,
                ErrorFileUsbHidLoaderFailed,
                ErrorFileUsbHidLoaderHIDState,
                ErrorFileUsbHidLoaderTimeOut,
                ErrorFileUsbHidLoaderChecksum,
                ErrorFileUsbHidLiaderUnknownError,
                ErrorLogOutNotPossible,
                ErrorLogOutQuerySessionFailed,
			};
//#ifdef Q_MOC_RUN
//			Q_ENUM(ErrorDecscription)
//#endif
//#ifdef Q_MOC_RUN
//		};
//#endif
			enum class IdentifierFlag
			{
				RemoteService,
				RemoteApp,
				RemoteView
			};

	}

}
Q_DECLARE_METATYPE(RW::COM::MessageDescription);
Q_DECLARE_METATYPE(RW::COM::ErrorDecscription);