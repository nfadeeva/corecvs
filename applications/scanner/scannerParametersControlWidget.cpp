/**
 * \file scannerParametersControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "scannerParametersControlWidget.h"
#include "ui_scannerParametersControlWidget.h"
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"


ScannerParametersControlWidget::ScannerParametersControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::ScannerParametersControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->channelComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->algoComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->redThresholdSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->heightSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->graphLineSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->useSSECheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->calculateConvolutionCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->calibrationModeCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->cornerScoreSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->harrisAppertureSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
}

ScannerParametersControlWidget::~ScannerParametersControlWidget()
{

    delete mUi;
}

void ScannerParametersControlWidget::loadParamWidget(WidgetLoader &loader)
{
    ScannerParameters *params = createParameters();
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
    delete params;
}

void ScannerParametersControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    ScannerParameters *params = createParameters();
    saver.saveParameters(*params, rootPath);
    delete params;
}

 /* Composite fields are NOT supported so far */
void ScannerParametersControlWidget::getParameters(ScannerParameters& params) const
{

    params.setChannel          (static_cast<ImageChannel::ImageChannel>(mUi->channelComboBox->currentIndex()));
    params.setAlgo             (static_cast<RedRemovalType::RedRemovalType>(mUi->algoComboBox->currentIndex()));
    params.setRedThreshold     (mUi->redThresholdSpinBox->value());
    params.setHeight           (mUi->heightSpinBox->value());
    params.setGraphLine        (mUi->graphLineSpinBox->value());
    params.setUseSSE           (mUi->useSSECheckBox->isChecked());
    params.setCalculateConvolution(mUi->calculateConvolutionCheckBox->isChecked());
    params.setCalibrationMode  (mUi->calibrationModeCheckBox->isChecked());
    params.setCornerScore      (mUi->cornerScoreSpinBox->value());
    params.setHarrisApperture  (mUi->harrisAppertureSpinBox->value());

}

ScannerParameters *ScannerParametersControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/


    ScannerParameters *result = new ScannerParameters(
          static_cast<ImageChannel::ImageChannel>(mUi->channelComboBox->currentIndex())
        , static_cast<RedRemovalType::RedRemovalType>(mUi->algoComboBox->currentIndex())
        , mUi->redThresholdSpinBox->value()
        , mUi->heightSpinBox->value()
        , mUi->graphLineSpinBox->value()
        , mUi->useSSECheckBox->isChecked()
        , mUi->calculateConvolutionCheckBox->isChecked()
        , mUi->calibrationModeCheckBox->isChecked()
        , mUi->cornerScoreSpinBox->value()
        , mUi->harrisAppertureSpinBox->value()
    );
    return result;
}

void ScannerParametersControlWidget::setParameters(const ScannerParameters &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->channelComboBox->setCurrentIndex(input.channel());
    mUi->algoComboBox->setCurrentIndex(input.algo());
    mUi->redThresholdSpinBox->setValue(input.redThreshold());
    mUi->heightSpinBox->setValue(input.height());
    mUi->graphLineSpinBox->setValue(input.graphLine());
    mUi->useSSECheckBox->setChecked(input.useSSE());
    mUi->calculateConvolutionCheckBox->setChecked(input.calculateConvolution());
    mUi->calibrationModeCheckBox->setChecked(input.calibrationMode());
    mUi->cornerScoreSpinBox->setValue(input.cornerScore());
    mUi->harrisAppertureSpinBox->setValue(input.harrisApperture());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void ScannerParametersControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    ScannerParameters *inputCasted = static_cast<ScannerParameters *>(input);
    setParameters(*inputCasted);
}
